from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
sys.setrecursionlimit(100000)


n,m=mdata()
C=list(mdata())
g=dd(set)
d=dd(set)
for i in range(m):
    a,b=mdata()
    c1=C[a-1]
    c2=C[b-1]
    if c1!=c2:
        d[c1].add(c2)
        d[c2].add(c1)
m=0
ind=C[0]
for i in sorted(d.keys()):
    if len(d[i])>m:
        m=len(d[i])
        ind=i
print(ind)