from collections import *
from itertools import *
from bisect import *
import copy

n,k=map(int,input().split())
mod=10**9+7
fac=[0,1]
for i in range(2,2*n+1):
    fac.append(fac[i-1]*i%mod)
ifac=[pow(i,mod-2,mod) for i in fac]

def comb(a,b):
    if a==0 and b==0:return(1)
    if a<b or a<0:return(0)

    return((fac[a]*ifac[a-b]*ifac[b])%mod)

count=1
for m in range(0,min(k+1,n)):

    count=(count+comb(n,m)*comb((n-m)+m-1,n-m-1))%mod
print(count)
