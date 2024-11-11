# This code is contributed by Siddharth

from sys import *
input = stdin.readline




import random
from bisect import *
import math
from collections import *
import operator
from heapq import *
from itertools import *
inf=10**18
mod=10**9+7

# inverse modulo power pow(a,-1,mod) - it only works on py 3.8 ( *not in pypy )



# ==========================================> Code Starts Here <=====================================================================



n,m=map(int,input().split())
dp=[0]*(n+5)
suf=[0]*(n+5)
dp[n]=1
suf[n]=1
for i in range(n-1,0,-1):
    dp[i]=(dp[i]+suf[i+1])%m
    suf[i]=suf[i+1]
    j=2
    while j*i<=n:
        l=j*i
        r=min(j*i+j-1,n)
        dp[i]=(dp[i]+suf[l]-suf[r+1])%m
        j+=1
    suf[i]=(suf[i+1]+dp[i])%m

print(dp[1]%m)









