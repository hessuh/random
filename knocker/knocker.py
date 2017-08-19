#!/usr/bin/env python3
import socket
import argparse

def send_packet(ip, port, msg):
    sock.sendto(msg.encode('utf-8'), (ip, port))

def arg_parse():
    parser = argparse.ArgumentParser()
    parser.add_argument('ip', nargs=1, help='ip')
    parser.add_argument('port', nargs=1, help='port')
    parser.add_argument('msg', nargs=1, help='msg')
    return parser.parse_args()

if __name__ == "__main__":
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    args = arg_parse()

    send_packet(args.ip[0], int(args.port[0]), args.msg[0])


