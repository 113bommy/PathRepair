import sys
import math
import collections
import bisect
import itertools
import decimal
import copy
import heapq

# import numpy as np

# sys.setrecursionlimit(10 ** 6)
INF = 10 ** 20
MOD = 10 ** 9 + 7
# MOD = 998244353

ni = lambda: int(sys.stdin.readline().rstrip())
ns = lambda: map(int, sys.stdin.readline().rstrip().split())
na = lambda: list(map(int, sys.stdin.readline().rstrip().split()))
na1 = lambda: list(map(lambda x: int(x) - 1, sys.stdin.readline().rstrip().split()))
flush = lambda: sys.stdout.flush()


# ===CODE===
def main():
    t = ni()

    for _ in range(t):
        n = ni()
        a = na()
        c = collections.Counter(a)
        x = -1
        y = -1
        bflg = True
        for i in range(max(a) + 1):
            if i in c.keys():
                if c[i] >= 2:
                    x = i
                    if bflg:
                        y = i
                elif c[i] >= 1:
                    x = i
                    bflg = False
            else:
                break

        x += 1
        y += 1

        print(x + y)


if __name__ == '__main__':
    main()
