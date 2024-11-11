#!/usr/bin/env python3
from math import gcd
n=int(input())
a=list(map(int,input().split()))
m=[0]*n
L,R=[0]*(n+1),[0]*(n+1)
for i in range(1,n+1):
    L[i]=gcd(L[i-1],a[i-1])
    R[n-i]=gcd(R[n-i+1],a[n-i])
for i in range(n):
    m[i]=gcd(L[i],R[i+1])
print(max(m))