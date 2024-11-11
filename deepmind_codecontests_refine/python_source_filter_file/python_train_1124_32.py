#!/usr/bin/env python3
#エクサウィザーズ2019 C

import sys
import math
import bisect
sys.setrecursionlimit(1000000000)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n,q = LI()
s = input()
l,r = -1,n
td = [list(map(str,input().split())) for _ in range(q)]
for i in range(q)[::-1]:
    t,d = td[i]
    if d == 'R':
        if r >= 0:
            if s[r-1] == t:
                r -= 1
        if l >= 0:
            if s[l] == t:
                l -= 1
    elif d == 'L':
        if l < n-1:
            if s[l+1] == t:
                l += 1
        if r < n-1:
            if s[r] == t:
                r += 1
print(max(0,r-l-1))
