from sys import stdin, stdout
from collections import Counter, defaultdict
import heapq


#range = xrange # not for python 3.0+

# main code
mod=10**9+7
ans=0
a,b=map(int,stdin.read().split())
for i in range(1,b):
    #print val
    val=a
    t1=(val*(val+1))/2
    t1%=mod
    t1=(t1*b)%mod
    
    temp=(t1*i)%mod
    temp=(temp+((i*val)%mod))%mod
    ans=(ans+temp)%mod
print(ans)

