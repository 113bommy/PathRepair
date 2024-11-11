#!/usr/bin/env python3

from sys import stdin
from math import ceil
from decimal import Decimal

secs_per_square = 16
secs_per_row = 6

secs_in_row = {'f': 1, 'e': 2, 'd': 3, 'a': 4, 'b': 5, 'c': 6}


def main():
    ns = stdin_get_string_from_line()
    n = int(ns[:-1])
    s = ns[-1]

    #print(n)

    square, order = get_square_and_pos(n)

    secs = secs_per_square * (square - 1)

    if order == 1:
        secs += secs_per_row + 1

    secs += secs_in_row[s]

    print(secs)

    return


def get_square_and_pos(row):
    square = ceil(Decimal(row)/4)
    if ceil((row+1)/4) != square:
        pos_in_square = 4
    elif ceil((Decimal(row+2))/4) != square:
        pos_in_square = 3
    elif ceil((Decimal(row+3))/4) != square:
        pos_in_square = 2
    else:
        pos_in_square = 1

    #print(square, pos_in_square)
    #print(square)

    if pos_in_square in (1, 3):
        order = 0
    else:
        order = 1

    return square, order


def stdin_get_ints_from_line():
    return (int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_ints_list_from_line():
    return list(int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_string_from_line():
    return stdin.readline().strip()


if __name__ == '__main__':
    main()
