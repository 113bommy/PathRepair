#This code is contributed by Siddharth
from bisect import *
import math
from collections import *
from heapq import *
from itertools import *
inf=10**18
mod=10**9+7






# ==========================================> Code Starts Here <=====================================================================


n,x,pos=map(int,input().split())
# pos-=1
l=0
r=n
bache=n-1
bade=n-x
chotte=x-1
ans=1
while l<r:
    mid=(l+r)//2
    if mid==pos:
        break
    elif mid>pos:
        ans=(ans*bade)%mod
        bade-=1
        bache-=1
        r=mid
    else:
        ans=(ans*chotte)%mod
        chotte-=1
        bache-=1
        l=mid+1
for i in range(1,bache+1):
    ans=(ans*i)%mod
print(ans)
































