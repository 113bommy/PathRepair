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

n,m = inpl()
a = inpl(); a.sort()
seen = set(a)
q = deque()
for x in a:
    if not x-1 in seen:
        q.append(x-1)
        seen.add(x-1)
    if not x+1 in seen:
        q.append(x+1)
        seen.add(x+1)
res = []
dist = 0
for _ in range(m):
    now = q.popleft()
    it = bisect_left(a,now)
    mi = abs(a[it]-now) if 0<=it<n else INF
    if it-1>0: mi = min(mi, abs(a[it-1]-now))
    if it+1<n: mi = min(mi, abs(a[it+1]-now))
    dist += mi
    res.append(now)
    if not now-1 in seen:
        q.append(now-1)
        seen.add(now-1)
    if not now+1 in seen:
        q.append(now+1)
        seen.add(now+1)
print(dist)
print(*res)