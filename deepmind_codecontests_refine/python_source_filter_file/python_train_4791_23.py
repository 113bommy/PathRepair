#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys


def get_parent(index):
    return index // 2


def get_left(index):
    return 2 * index


def get_right(index):
    return get_left(index) + 1


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    array_length = int(_input[0])
    array = list(map(int, _input[1].split()))
    array.insert(0, None)
    for i in range(1, array_length + 1):
        parent, left, right = get_parent(i), get_left(i), get_right(i)
        print('node ' + str(i) + ': ', end='')
        print('key = ' + str(array[i]) + ', ', end='')
        if parent:
            print('parent key = ' + str(array[parent]) + ', ', end='')
        if left <= array_length:
            print('left key = ' + str(array[left]) + ', ', end='')
        if right <= array_length:
            print('right key = ' + str(array[right]) + ',', end='')
        print('')