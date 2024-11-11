import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

for _ in range(inp()):
    n,p,k = inpl()
    a = inpl()
    a.sort()
    aa = list(itertools.accumulate(a))
    aa[k-1] = a[k-1]
    for j in range(k):
        now = 0
        for ind,i in enumerate(range(j,n)[::k]):
            if ind == 0:
                now = a[i]
                continue
            now += a[i]
            aa[i] = now
    res = 0
    for i in range(n):
        if p >= aa[i]:
            res = i+1
    print(res)