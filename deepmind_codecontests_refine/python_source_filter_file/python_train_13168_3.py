# -*- coding: utf-8 -*-
"""
Created on Thu Sep 26 08:04:33 2019

@author: avina
"""

n,m = map(int, input().split())
B = {}
S = {}
for i in range(n):
    a,b,c = input().split()
    
    if a == 'B':
        w = -1 + int(b) + int(c)
        if (a,int(b)) not in B:
            B[(a,int(b))] = int(c)
        else:
            B[(a,int(b))] += int(c)
    else:
        if (a,int(b)) not in S:
            S[(a,int(b))] = int(c)
        else:
            S[(a,int(b))] += int(c)

l = []
for i in B:
    a,b = i
    l.append((a,b,B[i]))
r = []
for i in S:
    a,b = i
    r.append((a,b,S[i]))
l.sort(key = lambda x:x[1],reverse=True)
r.sort(key = lambda x:x[1])
for i in range(min(m,len(r))):
    print(*r[i])
for i in range(min(m,len(l))):
    print(*l[i])
    