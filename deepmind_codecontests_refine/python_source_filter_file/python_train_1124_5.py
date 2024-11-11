# -*- coding: utf-8 -*-
"""
Created on Sat Mar 30 21:21:19 2019

@author: Yamazaki Kenichi
"""

N,Q = map(int,input().split())
s = input()
A = [list(input().split()) for i in range(Q)]

def a(b,i):
    if i == -1 or i == N:
        return i        
    if b[0] == s[i]:
        return i - 1 if b[1] == 'L' else i + 1
    else:
        return i
def ar(i):
    for j in range(Q):
        if i == N:
            return False
        i = a(A[j],i)
    return False if i == N else True
def al(i):
    for j in range(Q):
        if i == -1:
            return False
        i = a(A[j],i)
    return False if i == -1 else True
def bir(i,j):
    if i + 1 == j:
        return i
    if ar((i+j)//2):
        return bir((i+j)//2,j)
    else:
        return bir(i,(i+j)//2)
def bil(i,j):
    if i + 1 == j:
        return i
    if al((i+j)//2):
        return bil(i,(i+j)//2)
    else:
        return bil((i+j)//2,j)
ans = bir(0,N) - bil(0,N)
print(ans)