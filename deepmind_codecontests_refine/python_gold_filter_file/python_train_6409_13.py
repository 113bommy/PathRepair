#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import _bisect
n,m,k=[int(x) for x in input().split()]
x,s=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]
c=[int(x) for x in input().split()]
d=[int(x) for x in input().split()]
a.append(x)
b.append(0)
r=n*x
for i in range(m+1):
    if b[i]>s:
        continue
    if s-b[i]<d[0]:
        r=min(r,n*a[i])
        continue
    j=_bisect.bisect_right(d,s-b[i],0,k)-1
    r=min(r,(n-c[j])*a[i])
print(r)
