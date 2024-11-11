from fractions import gcd
from datetime import date
from math import factorial
import functools
from heapq import*
from collections import deque
import collections
import math
from collections import defaultdict, Counter
import sys
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
inf = float("inf")


def main():
    n = int(input())
    a = list(map(int, input().split()))
    d = Counter(a)
    ans = 0
    for k in a:
        d[k] -= 1
        for i in range(32):
            if 2 ** i - k < 0:
                continue
            if d[2 ** i - k] > 0:
                ans += d[2 ** i - k]
    print(ans)


if __name__ == '__main__':
    main()
