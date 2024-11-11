# -*- coding: utf-8 -*-

import sys


def rli():
    return list(map(int, input().split()))


def solve():
    cache = {}

    def guess(x, y):
        if (x, y) not in cache:
            print('? {} {}'.format(x, y))
            sys.stdout.flush()
            res = input()
            cache[(x, y)] = res
        return cache[(x, y)]

    st, ed = 1, 2

    while guess(st, ed) == 'y':
        st, ed = ed, ed + ed

    if st == 1 and ed == 2 and guess(2, 3) == 'x':
        print('! 1')
        return

    x = 1 << 32
    while x:
        if ed - x > st and guess(st, ed - x) == 'x':
            ed -= x
        x >>= 1
    print('! {}'.format(st + 1))


def main():
    while True:
        s = input()
        if s == 'start':
            solve()
        else:
            break


if __name__ == '__main__':
    main()
