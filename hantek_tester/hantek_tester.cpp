// hantek_tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include "DefMacro.h"
#include "HTSoftDll.h"
#include "HTHardDll.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>

constexpr size_t FIRST_ENABLED_CHAN = 0;
constexpr size_t NR_ENABLED_CHANS = 4;
constexpr int TRIGGER_CHANNEL = CH1;
constexpr int TRIGGER_SLOPE = RISE;
constexpr int TRIGGER_MODE = EDGE;
constexpr int TRIGGER_COUPLE = DC;

static
WORD calibration_data[CAL_LEVEL_LEN];

static
WORD amp_level[AMPCALI_Len];

short find_devs()
{
    short dev_info[MAX_USB_DEV_NUMBER];
    WORD nr_devs = dsoHTSearchDevice(dev_info);

    ULONG fpga_version = 0,
        hard_version = 0;

    RELAYCONTROL relay_control;
    CONTROLDATA control_data;

    std::cout << "Found " << nr_devs << " devices" << std::endl;

    for (size_t i = 0; i < nr_devs; i++) {
        std::cout << "    device: " << dev_info[i] << std::endl;
    }

    short dev_idx = 0; // For now, assume we're just opening the first device we found.

    // This is broken?
    //if (FALSE == dsoSetUSBBus(dev_idx)) {
    //    std::cout << "Failed to dsoSetUSBBus()" << std::endl;
    //    nr_devs = 0;
    //    goto done;
    //}

    if (1 == dsoHTDeviceConnect(dev_idx)) {
        std::cout << "Device is connected!" << std::endl;
    }
    else {
        std::cerr << "Device connection failure, aborting." << std::endl;
        nr_devs = 0;
        goto done;
    }

    if (0 == dsoInitHard(dev_idx)) {
        std::cerr << "Error while initializing device " << dev_idx << std::endl;
        nr_devs = 0;
        goto done;
    }

    fpga_version = dsoGetFPGAVersion(dev_idx);
    hard_version = dsoGetHardVersion(dev_idx);
    std::cout << "FPGA version: 0x" << std::ios::hex <<  std::setw(4) << std::setfill('0') << fpga_version << " Hardware version: 0x" << hard_version << std::endl;

    std::cout << "Initializing ADC" << std::endl;

    memset(calibration_data, 0, sizeof(calibration_data));
    
    // Not sure what we're doing here, but I think this sets the ADC gain
    if (0 == dsoHTADCCHModGain(dev_idx, 4)) {
        std::cerr << "Failed to set ADC Channel Mod Gain, aborting." << std::endl;
        goto done;
    }

    // Read back the calibration data for the device
    if (0 == dsoHTReadCalibrationData(dev_idx, calibration_data, CAL_LEVEL_LEN)) {
        std::cerr << "Failed to read calibration data, aborting." << std::endl;
        goto done;
    }

    // Not sure what this is doing to the calibration data, yet
    if (calibration_data[CAL_LEVEL_LEN - 1] != ZERO_FLAG) {
        std::cout << "Preparing the calibration data " << std::endl;

        for (size_t i = 0; i < ZEROCALI_LEN; i++) {
            size_t chan = i % ZEROCALI_PER_CH_LEN;
            size_t volt = chan / ZEROCALI_PER_VOLT_LEN;

            if (volt == 5 || volt == 8 || volt == 11) {
                switch (chan % ZEROCALI_PER_VOLT_LEN) {
                case 0:
                    calibration_data[i] = 16602;
                    break;
                case 1:
                    calibration_data[i] = 60111;
                    break;
                case 2:
                    calibration_data[i] = 17528;
                    break;
                case 3:
                    calibration_data[i] = 59201;
                    break;
                case 4:
                    calibration_data[i] = 17710;
                    break;
                case 5:
                    calibration_data[i] = 58900;
                    break;
                default:
                    calibration_data[i] = 0;
                    break;
                }
            }
        }
    }

    // Set  up the "amplifier level" which is probably an amplifier gain
    for (size_t i = 0; i < AMPCALI_Len; i++) {
        amp_level[i] = 1024;
    }

    // Set up the relay control
    memset(reinterpret_cast<void *>(&relay_control), 0, sizeof(relay_control));
    for (size_t i = FIRST_ENABLED_CHAN; i < NR_ENABLED_CHANS; i++) {
        relay_control.bCHEnable[i] = 1;
        relay_control.nCHVoltDIV[i] = 8;
        relay_control.nCHCoupling[i] = DC;
        relay_control.bCHBWLimit[i] = 0;
    }
    relay_control.nTrigSource = TRIGGER_CHANNEL;
    relay_control.bTrigFilt = 0;
    relay_control.nALT = 0;

    control_data.nCHSet = 0xf; // FIXME
    control_data.nTimeDIV = 12; // Wat
    control_data.nTriggerSource = TRIGGER_CHANNEL;
    control_data.nHTriggerPos = 50;
    control_data.nVTriggerPos = 128;
    control_data.nTriggerSlope = TRIGGER_SLOPE;
    control_data.nBufferLen = BUF_4K_LEN;
    control_data.nReadDataLen = BUF_4K_LEN;
    control_data.nAlreadyReadLen = 0;
    control_data.nALT = 0;

    std::cout << "Setting the DSO Sampling Rate" << std::endl;
    if (0 == dsoHTSetSampleRate(dev_idx, amp_level, YT_NORMAL, &relay_control, &control_data)) {
        std::cerr << "Failed to set sample rate, aborting..." << std::endl;
        goto done;
     }

    std::cout << "Setting CH and trigger" << std::endl;
    if (0 == dsoHTSetCHAndTrigger(dev_idx, &relay_control, control_data.nTimeDIV)) {
        std::cerr << "Failed to set time time division???" << std::endl;
        goto done;
    }

    std::cout << "Setting RAM and trigger control" << std::endl;
    if (0 == dsoHTSetRamAndTrigerControl(dev_idx, control_data.nTimeDIV, control_data.nCHSet, control_data.nTriggerSource, 0)) {
        std::cerr << "Failed to set RAM and trigger control" << std::endl;
        goto done;
    }

    std::cout << "Setting each channel position to 0" << std::endl;
    for (size_t i = 0; i < MAX_CH_NUM; i++) {
        if (0 == dsoHTSetCHPos(dev_idx, calibration_data, relay_control.nCHVoltDIV[i], 128, i, 4)) {
            std::cerr << "Failed to set channel position for channel " << i << std::endl;
            goto done;
        }
    }

    // Set the trigger mode
    std::cout << "Set trigger mode to EDGE, DC coupled" << std::endl;
    if (0 == dsoHTSetTrigerMode(dev_idx, TRIGGER_MODE, TRIGGER_SLOPE, TRIGGER_COUPLE)) {
        std::cerr << "Failed to set trigger mode, aborting" << std::endl;
        goto done;
    }
done:
    return nr_devs;
}

int main()
{
    std::cout<< "The Hantek Tester" << std::endl;

    find_devs();

    return EXIT_SUCCESS;
}


