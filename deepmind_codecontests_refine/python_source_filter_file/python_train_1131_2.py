# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0101&lang=jp
"""
import sys


def solve(data):
    result = data.replace('Hoshino', 'Hoshina')
    return result


def main(args):
    num = int(input())
    for _ in range(num):
        data = input().strip()
        result = solve(data)
        print(result)


if __name__ == '__main__':
    main(sys.argv[1:])