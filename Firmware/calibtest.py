#!/usr/bin/env python3
import argparse
import logging
import struct

vpd_to_scale = {
    0: 50.0,
    1: 20.0,
    2: 10.0,
    3: 5.0,
    4: 2.0,
    5: 1.0,
    6: 5.0,
    7: 2.0,
    8: 1.0,
    9: 5.0,
    10: 2.0,
    11: 1.0,
};

def _setup_logging(verbose):
    """
    Set logging verbosity, 
    """
    if verbose:
        logging.basicConfig(level=logging.DEBUG)
    else:
        logging.basicConfig(level=logging.INFO)

def main():
    parser = argparse.ArgumentParser(description='Test calibration algorithm for Hantek DSO6xx4')
    parser.add_argument('-v', '--verbose', help='verbose output', action='store_true')
    parser.add_argument('-N', '--num-chans', help='number of ADC channels', type=int)
    parser.add_argument('-V', '--volt-per-div', help='voltage per division coefficient', type=int)
    parser.add_argument('-p', '--position', help='offset, [-127, 128]', type=int)
    parser.add_argument('in_file', help='The file to process')
    args = parser.parse_args()

    _setup_logging(args.verbose)

    logging.debug('Processing Calibration Table from {}'.format(args.in_file))

    if args.num_chans == 2:
        mode_map = 2
    elif args.num_chans == 4:
        mode_map = 4
    elif args.num_chans == 1:
        mode_map = 0
    else:
        raise Exception('Unsupported number of ADC channels: {}'.format(args.num_chans))

    if args.volt_per_div >= 0 and args.volt_per_div < 6:
        base = 0x3c
    elif args.volt_per_div >= 6 and args.volt_per_div < 9:
        base = 0x60
    elif args.volt_per_div >= 9 and args.volt_per_div < 12:
        base = 0x84
    else:
        raise Exception('Unknown volts-per-division value: {}'.format(args.volt_per_div))

    with open(args.in_file, 'rb') as fp:
        raw = fp.read()

        # Sheisty!!!
        calib = struct.unpack('H'*(len(raw)//2), raw)

    logging.debug('Calibration length: {}'.format(len(calib)))

    for i in [0, 1, 2, 3]:
        line = calib[144 * i:144 * (i + 1)]
        logging.debug('At {} -> Len: {}'.format(i, len(line)))

        hi = line[base + mode_map]
        lo = line[base + mode_map + 1]
        logging.debug('  Hi: {} Lo: {}'.format(hi, lo))

        scale = vpd_to_scale[args.volt_per_div]

        v = int(((hi + lo)/2.0) + 0.5)
        x = (lo - v)/scale
        q = int(x + 0.5)
        upper = v + q
        lower = v - q

        offset = ((upper - lower)/255.0) * args.position + lower
        logging.debug('    upper = {} lower = {} v = {} q = {} scale = {} offset = {}'.format(upper, lower, v, q, scale, offset))

        logging.info('  Ch: {} offset = {:04x}'.format(i, int(offset)))

if __name__ == '__main__':
    main()
