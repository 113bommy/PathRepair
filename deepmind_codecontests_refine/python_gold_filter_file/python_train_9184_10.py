from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
#sys.setrecursionlimit(100000)

n,h,l,r=mdata()
A=list(mdata())
dp=[0]*h
k=0
for i in range(n):
    k=(k+A[i])%h
    ndp=[]
    for j in range(min(i+2,h)):
        t=k-j
        if t<0:
            t+=h
        m=max(dp[j],dp[j-1])
        if l<=t<=r:
            m+=1
        ndp.append(m)
    ndp+=[0]*(h-len(ndp))
    dp=ndp
print(max(dp))

