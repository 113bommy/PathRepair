#!/usr/bin/env python3

from sys import stdin


def main():
    x, = stdin_get_ints_from_line()
    a = stdin_get_ints_list_from_line()

    minn = min(a)
    maxx = max(a)
    mid = (maxx + minn) / 2

    #print(minn, maxx, mid)

    for n in a:
        if n not in (minn, maxx, mid):
            return 'NO'

    return 'YES'


def stdin_get_ints_from_line():
    return (int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_ints_list_from_line():
    return list(int(x) for x in stdin.readline().strip().split(' '))


def stdin_get_string_from_line():
    return stdin.readline().strip()


if __name__ == '__main__':
    print(main())
