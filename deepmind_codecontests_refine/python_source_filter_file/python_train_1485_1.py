from __future__ import division, print_function
import sys
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
#from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------

from heapq import heapify, heappop as pp, heappush as pus
n,m =mapi()
a = list(mapi())
b = []
gr = defaultdict(list)
for i in range(m):
    x,y = mapi()
    x,y = x-1,y-1
    a[x]-=1
    a[y]-=1
    gr[x].append([y,i])
    gr[y].append([x,i])
q = deque()
for i in range(n):
    if a[i]>=0:
        a[i]==float("inf")
        q.append(i)
vis = {}
res =[]
while q:
    node = q.popleft()
    for w,i in gr[node]:
        if w not in vis:
            res.append(i)
        if a[w]==float("inf"):continue
        a[w]+=1
        if a[w]>=0:
            q.append(w)
            a[w] = float("inf")
    vis[node] = 1
if len(res)==m:
    print("ALIVE")
    print(*[i+1 for i in res[::-1]])
else:
    print("DEAD")
