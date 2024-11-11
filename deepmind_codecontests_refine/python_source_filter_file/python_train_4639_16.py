#!/usr/bin/env python3

from sys import stdin
from math import sqrt


def main():
    a, b = stdin_get_ints_from_line()
    n, = stdin_get_ints_from_line()

    result = list()

    for i in range(n):
        x, y, v = stdin_get_ints_from_line()
        t = sqrt((a-x)**2 + (b-y)**2)

        result.append(t)

    print(min(result))

    return


def stdin_get_ints_from_line():
    return (int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_ints_list_from_line():
    return list(int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_string_from_line():
    return stdin.readline().strip()


if __name__ == '__main__':
    main()
