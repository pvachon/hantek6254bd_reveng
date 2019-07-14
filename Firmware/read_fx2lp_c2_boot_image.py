#!/usr/bin/env python3
import argparse
import logging
import struct

def _setup_logging(verbose):
    """
    Set logging verbosity, 
    """
    if verbose:
        logging.basicConfig(level=logging.DEBUG)
    else:
        logging.basicConfig(level=logging.INFO)

def load_c2_header(fp):
    fp.seek(0, 0)
    header = fp.read(8)
    magic, vid, pid, did, cfg = struct.unpack('=BHHHB', header)
    logging.debug('Magic: {:02x} VID,PID,DID: {:04x}-{:04x}-{:04x} cfg: 0x{:02x}'.format(magic, vid, pid, did, cfg))
    return {'magic': magic, 'vid':vid, 'pid':pid, 'did':did, 'cfg': cfg}

def _read_block_header(fp):
    blk_header = fp.read(4)

    if not blk_header:
        raise Exception('End of file - missing termination sentinels')

    length, start_addr = struct.unpack('>HH', blk_header)
    logging.debug('Block: Start Address: 0x{:04x} - Length = {:04x}'.format(start_addr, length))
    return length, start_addr

def load_blocks(fp):
    blocks = []
    fp.seek(8, 0)
    while True:
        length, start_addr = _read_block_header(fp)
        if length == 0x8001 and start_addr == 0xe600:
            break
        raw = fp.read(length)
        blocks.append({'addr': start_addr, 'data': raw})
    return blocks

def main():
    parser = argparse.ArgumentParser(description='Parse and extract image/details from FX2LP C2 image')
    parser.add_argument('-v', '--verbose', help='verbose output', action='store_true')
    parser.add_argument('in_file', help='The file to process')
    parser.add_argument('out_file', help='Output file for the complete binary')
    args = parser.parse_args()

    _setup_logging(args.verbose)

    logging.debug('Processing image {}'.format(args.in_file))

    with open(args.in_file, 'rb') as fp:
        header = load_c2_header(fp)

        if header['magic'] != 0xc2:
            raise Exception('Invalid header magic: this is not a C2 Boot Image')

        logging.debug('Loading blocks')
        blocks = load_blocks(fp)

        logging.debug('Writing to file {}'.format(args.out_file))

        with open(args.out_file, 'wb+') as ofp:
            for block in blocks:
                logging.debug('Writing block for address 0x{:04x}'.format(block['addr']))
                ofp.write(block['data'])


if __name__ == '__main__':
    main()
