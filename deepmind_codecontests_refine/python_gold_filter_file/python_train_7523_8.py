# -*- coding: utf-8 -*-
import sys, string
from collections import deque, defaultdict
from math import sqrt, factorial, gcd, ceil, atan, pi, log2
# def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline().strip() # warning bytes
def input(): return sys.stdin.buffer.readline().decode('utf-8')
# string.ascii_lowercase
from bisect import bisect_left, bisect_right
from operator import add
MOD = int(1e9)+7
INF = float('inf')

# sys.setrecursionlimit(int(1e6))


def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    m = defaultdict(int)

    total = 0
    segs = []
    m[0] = -1
    ans = 0
    last = -INF
    for i in range(n):
        total += a[i]
        if total in m and last <= m[total]:
            ans += 1
            last = i

        m[total] = i + 1

   
    print(ans)

    
    

T = 1
# T = int(input())
for case in range(1,T+1):
    # try:
        ans = solve()
    # except:
    #     import traceback
    #     print(traceback.format_exc())

"""

5

1 2 3 4





"""

