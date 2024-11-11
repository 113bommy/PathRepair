#!/usr/bin/env python3
#EDPC P

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
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

n = I()
graph = [[] for _ in range(n)]
for _ in range(n-1):
    x,y = LI()
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)

dp = [[1,1] for _ in range(n)]
flg = [0]*n
def f(v):
    flg[v] = 1
    for u in graph[v]:
        if flg[u]:
            continue
        f(u)
        dp[v][0] *= (dp[u][0]+dp[u][1])
        dp[v][0] %= mod
        dp[v][1] *= dp[u][0]
        dp[v][1] %= mod

f(0)
ans = (dp[0][0] + dp[0][1]) % mod
print(ans)
