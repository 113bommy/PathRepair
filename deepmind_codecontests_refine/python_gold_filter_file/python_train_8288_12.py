#! /usr/bin/env python3

import sys


def main():
    solve()


def solve():
    data = sys.stdin.readlines()
    stations_a_to_b, first, second = parse(data)
    output = calc_trip(stations_a_to_b, first, second)
    print(output)


def parse(data):
    return tuple(s.rstrip() for s in data)


def calc_trip(stations_a_to_b, first, second):
    a_to_b = is_2_substr_of(first, second, stations_a_to_b)
    b_to_a = is_2_substr_of(first, second, stations_a_to_b[::-1])

    if a_to_b:
        if b_to_a:
            return 'both'
        else:
            return 'forward'
    elif b_to_a:
        return 'backward'
    return 'fantasy'


def is_2_substr_of(ss1, ss2, text):
    a = text.find(ss1)
    if a == -1:
        return False
    return text.find(ss2, a + len(ss1)) != -1


if __name__ == '__main__':
    main()
