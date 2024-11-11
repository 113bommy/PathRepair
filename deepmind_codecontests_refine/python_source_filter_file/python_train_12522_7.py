import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7



n,m=mdata()
A=data()
B=data()
dp=[[0]*(m+1) for i in range(n+1)]
ans=0
for i in range(n):
    for j in range(m):
        if A[i]==B[j]:
            dp[i+1][j+1]=max(dp[i][j],0)+2
        else:
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])-1
    ans=max(ans,max(dp[i]))
out(ans)


