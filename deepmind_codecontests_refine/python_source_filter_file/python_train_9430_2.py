#!/usr/bin/env python3

import sys


def vowels(k):
    return k.count('a') \
        + k.count('e') \
        + k.count('i') \
        + k.count('o') \
        + k.count('u')


def main():
    a = sys.stdin.readlines()

    for line in a[3:]:
        if line.strip() != '':
            print("NIE")
            return

    if vowels(a[0]) != 5 or vowels(a[1]) != 7 or vowels(a[2]) != 5:
        print("NIE")
        return

    print("TAK")

main()
