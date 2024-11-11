# -*- coding: utf-8 -*-
"""
Created on Wed Oct 16 20:35:46 2013

@author: Praveen Kumar
"""
import sys

m,n = map(int, input().split())
d = [0]*(m+1);
for i in range(n):
    a = list(map(int, input().split()))
    b = [1,2,3]
    for j in a:
        if d[j] != 0:
            b.remove(d[j])
            a.remove(j)
    if len(b) != 0:
        for j in range(len(a)):
            d[a[j]] = b[j]

#for i in range(1,len(d)):
#    sys.stdout.write(str(d[i])+" ")
print(' '.join(map(str, d[1:])));  