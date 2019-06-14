// hantek_tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include "DefMacro.h"
#include "HTSoftDll.h"
#include "HTHardDll.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>

short find_devs()
{
	short dev_info[MAX_USB_DEV_NUMBER];
	WORD nr_devs = dsoHTSearchDevice(dev_info),
		fpga_version = 0,
		hard_version = 0;

	std::cout << "Found " << nr_devs << " devices" << std::endl;

	for (size_t i = 0; i < nr_devs; i++) {
		std::cout << "    device: " << dev_info[i] << std::endl;
	}

	short dev_idx = 0; // For now, assume we're just opening the first device we found.

	// This is broken?
	//if (FALSE == dsoSetUSBBus(dev_idx)) {
	//	std::cout << "Failed to dsoSetUSBBus()" << std::endl;
	//	nr_devs = 0;
	//	goto done;
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
		std::cout << "Error while initializing device " << dev_idx << std::endl;
		nr_devs = 0;
		goto done;
	}

	fpga_version = dsoGetFPGAVersion(dev_idx);
	hard_version = dsoGetHardVersion(dev_idx);
	std::cout << "FPGA version: 0x" << std::ios::hex <<  std::setw(4) << std::setfill('0') << " Hardware version: 0x" << hard_version << std::endl;





done:
	return nr_devs;
}

int main()
{
    std::cout<< "The Hantek Tester" << std::endl;

	find_devs();

	return EXIT_SUCCESS;
}


