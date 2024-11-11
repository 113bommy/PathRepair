from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
#from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
#def print(x): return sys.stdout.write(str(x)+'\n')
#sys.setrecursionlimit(100000)
mod=int(1e9+7)

n,m=mdata()
dp=[[2,0,0]]
for i in range(1,m):
    dp.append([(2*dp[i-1][0]-dp[i-1][2]+mod)%mod,(dp[i-1][1]+dp[i-1][0]-dp[i-1][2]+mod)%mod,(dp[i-1][0]-dp[i-1][2]+mod)%mod])
cnt=dp[-1][1]
k1=dp[-1][0]-dp[-1][1]
k2=0
for i in range(1,n):
    k1,k2=(2*k1-k2+mod)%mod,(k1-k2+mod)%mod
print(cnt+k1)