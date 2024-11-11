#!/usr/bin/env python3

import math
from sys import stdin, stdout


def get_int():
    return int(stdin.readline().strip())


def prime(n):
    for i in range(2, int(math.sqrt(n))):
        if n % i == 0:
            return False
    return True


def main():
    write = stdout.write
    t = get_int()
    for _ in range(t):
        n = get_int()
        win = 0
        if n == 1:
            win = 1
        if n > 2 and n % 2 == 0:
            x = math.log10(n) / math.log10(2)
            if x == int(x):
                win = 1
            if n % 4 != 0 and prime(n / 2):
                win = 1
        if win % 2 == 0:
            write("Ashishgup\n")
        else:
            write("FastestFinger\n")
    pass


if __name__ == "__main__":
    main()
