import sys
import math
from collections import defaultdict


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


def solve():
    input()
    tab = rn()
    count1 = 0
    count2 = 0
    res = 0
    for e in tab:
        if e % 3 == 0:
            res += 1
        elif e % 3 == 1:
            count1 += 1
        elif e % 3 == 2:
            count2 += 1
    if count2 >= count1:
        print(res + count1 + (count1 - count2) // 3)
    else:
        print(res + count2 + (count1 - count2) // 3)


if __name__ == '__main__':
    test = int(input())
    for _ in range(test):
        solve()
