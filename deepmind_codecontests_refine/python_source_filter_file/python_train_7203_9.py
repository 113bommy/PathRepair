import bisect
import functools
import math
import sys
from collections import defaultdict

# input = sys.stdin.readline
from itertools import groupby

rt = lambda: map(int, input().split())
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))


def main():
    t = ri()
    for _ in range(t):
        n = ri()
        tot_len = 0
        num_odd = 0
        ones = 0
        for i in range(n):
            s = input()
            tot_len += len(s)
            if len(s) % 2 == 1:
                num_odd += 1
            ones += s.count('1')
        if num_odd % 2 == 0 and ones % 2 == 1:
            print(n-1)
        else:
            print(n)


if __name__ == '__main__':
    main()