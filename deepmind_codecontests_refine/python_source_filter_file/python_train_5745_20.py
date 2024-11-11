import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

for _ in range(inp()):
    n,m,k = inpl()
    h = inpl()
    for i in range(n-1):
        if h[i]+k >= h[i+1]:
            tmp = h[i+1]-k
            m += h[i]-tmp
        else:
            need = h[i+1]-k-h[i]
            if m < need:
                print('NO')
                break
            m -= need
    else: print('YES')