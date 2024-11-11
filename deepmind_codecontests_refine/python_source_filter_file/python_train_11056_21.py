from datetime import datetime

import math


class Read:
    @staticmethod
    def string():
        return input()

    @staticmethod
    def int():
        return int(input())

    @staticmethod
    def list(sep=' '):
        return input().split(sep)

    @staticmethod
    def list_int(sep=' '):
        return list(map(int, input().split(sep)))


def solve():
    x, y = Read.list_int()
    if x >= y:
        print('YES')
    elif x == 1:
        print('NO')
    else:
        x_new = x if x % 2 == 0 else x - 1
        x2_new = x_new * 1.5
        x3_new = x if x2_new % 2 == 0 else x2_new - 1
        if x2_new >= y:
            print('YES')
        else:
            print('NO' if x3_new <= x_new else 'YES')


# query_count = 1
query_count = Read.int()
while query_count:
    query_count -= 1
    solve()
