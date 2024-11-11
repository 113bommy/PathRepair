# -*- coding: utf-8 -*-
"""
Created on Tue Jul  7 16:08:14 2020

@author: Dell
"""


n,m=list(map(int,input().split()))
mod=998244353

#print(math.factorial(m)//(math.factorial(n-1)*math.factorial(m-n+1)))
if n>2:
    l=n-1
    c,d,u=[1],[1],[1]
    for i in range(1,l+1):
        c.append((c[-1]*(m-i+1))%mod)
        d.append((d[-1]*i)%mod)
        u.append(c[-1]*pow(d[i],mod-2,mod))
    p=u[l]
    print(((pow(2,n-3))*(n-2)*p)%mod)
else:
    print(m*(m-1))
