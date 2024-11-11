# -*- coding: utf-8 -*-
import sys
from collections import deque, defaultdict, namedtuple
from math import sqrt, factorial, gcd, ceil, atan, pi
def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline().strip() # warning bytes
# def input(): return sys.stdin.buffer.readline().decode('utf-8')
import string
import operator
# string.ascii_lowercase
from bisect import bisect_left, bisect_right
from functools import lru_cache, reduce
MOD = int(1e9)+7
INF = float('inf')


def solve():
    n, k = [int(x) for x in input().split()]
    if k * (k-1) < n:
        print("NO")
        return

    print("YES")
    ans = []

    cnt = 0
    for i in range(k):
        for j in range(i + 1, k):
            ans.append((i, j))
            ans.append((j, i))
            cnt += 2
            if cnt >= n: break
        if cnt >= n: break
    
    if cnt > n:
        ans.pop()
    
    if ans[0][0] == ans[-1][0]:
        ans[-1] = (k - 2, k - 1)
    
    for a, b in ans:
        print(a + 1, b + 1)



t = 1
# t = int(input())
for case in range(1,t+1):
    ans = solve()


"""


1 2
2 1
1 3
3 1
2 3
3 2





"""
