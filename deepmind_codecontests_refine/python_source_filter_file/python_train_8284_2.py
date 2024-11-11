#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import math
a=input()
mod=int(1e9+7)
ans=int(0)
sum=0
def pow(c):
    ans=1
    c=int(c)
    base=2
    while c:
        if c%2==1:
            ans=(ans*base)%mod
        base=(base*base)%mod
        c/=2
    return ans
for s in(a):
    if s=='b':
        if sum>=1:
            temp=int(pow(sum))
            ans+=(temp-1)
            ans%=mod
    else:
        sum+=1
print(ans)



