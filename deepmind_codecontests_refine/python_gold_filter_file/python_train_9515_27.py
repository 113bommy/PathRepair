# -*- coding: utf-8 -*-
"""
Created on Wed Dec  6 17:44:28 2017

@author: utada
"""

def utada(x,y):
    p = x
    while a[x] == y :
        x+=1
        if x == len(a):
            break
    p1 = x
    return p1-p 

def haru0(p):
    s0 = g[p]
    s1 = 0
    q = p+1 
    v = [a.count(1)+s0]
    s = 0
    while q+1 <len(g):
        s1 += g[q]
        s0 += g[q+1]
        s = a.count(1)+s0-s1
        q+=2
        v.append(s)
    return(max(v))

n = int(input())
g = []
b = []
q = 0
a = [int(i) for i in input().split()]
i = 0
if a[0] == 0:
    start = 0
else:
    start = 1
if a[len(a)-1] == 0:
    end = 0
else:
    end = 1
while i <len(a):
    if a[i] == 1 :
        if i == 0:
            f = utada(i,1)
            g.append(f)
        elif a[i-1] == 0:
            f = utada(i,1)
            g.append(f)
        
    if a[i] == 0: 
        if i == 0 :
            f = utada(i,0)
            g.append(f)
        elif a[i-1] == 1:
            f = utada(i,0)
            g.append(f)
    i += 1
for p in range(len(g)):
    if start == 0 and p%2 == 0:
            b.append(haru0(p))
    if start == 1 and p%2 != 0:
            b.append(haru0(p))
if b == []:
    b.append(a.count(1)-1)     
#print(g,b)
print(max(b))
            
                
                
        
