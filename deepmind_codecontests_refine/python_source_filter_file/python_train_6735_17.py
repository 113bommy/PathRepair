import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify, nlargest
from copy import deepcopy
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_1(): return list(map(lambda x:int(x)-1, sys.stdin.readline().split()))
def inps(): return sys.stdin.readline()
def inpsl(x): tmp = sys.stdin.readline(); return list(tmp[:x])
def err(x): print(x); exit()

n,k,l = inpl()
a = inpl(); a.sort()
if a[n-1]-a[0]>l: print(0); exit()
idx = n*k-k
res = 0
for i in range(idx+1)[::-1]:
    ans = a[i]-a[0]
    if ans<=l:
        cnt = i+1
        m = cnt//k
        idx = 0
        added = set()
        for _ in range(m):
            res += a[idx]
            added.add(idx)
            idx += k
        idx = i
        for i in range(n-m):
            if idx in added: idx -= 1
            res += a[idx]
            idx -= 1
        print(res)
        break
