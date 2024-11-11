# -*- coding: utf-8 -*-
n,k=input().split()
n=int(n);k=int(k)
if n%2==0:
    if k<=n//2:
        ans=2*k-1
    if k>n//2:
        ans=2*(k-n//2)
else:
    m=n+1
    if k<=m//2:
        ans=2*k-1
    if k>m//2:
        ans=2*(k-m//2)
print(ans)