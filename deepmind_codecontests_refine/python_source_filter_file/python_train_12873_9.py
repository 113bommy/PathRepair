#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys

def main():
    k, n, s, p = map(int, sys.stdin.readline().split())
    spp = n // s if not n % s else n//s +1
    tmp = spp * k // p
    tmp = tmp if not spp * k // p else tmp +1
    print(tmp)

main()
