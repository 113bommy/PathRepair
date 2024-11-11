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
    k = int(input())
    if k == 0:
        print(1)
        print(1)
        exit()
    elif k == 1:
        print(3)
        print("1 0 3")
        exit()
    a = min(k, 50)
    b = k % a
    ans = [i + k//a for i in range(a)]
    for i in range(b):
        ans.sort()
        for j in range(1, a):
            ans[j] -= 1
        ans[0] += a

    print(a)
    print(*ans)


if __name__ == '__main__':
    main()
