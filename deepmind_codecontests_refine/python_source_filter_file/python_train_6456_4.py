# -*- coding: utf-8 -*-
"""
Created on Sat Mar  2 17:11:49 2019

@author: Yamazaki Kenichi
"""

m = int(input())
A = [list(input().split()) for i in range(m)]

T = [[-1,-1,-1,-1]]
def insert(T,u,x):
    if T[0][3] == -1:
        T[0][3] = x
        return
    if x < T[u][3]:
        if T[u][1] == -1:
            T[u][1] = len(T)
            T.append([u,-1,-1,x])
        else:
            insert(T,T[u][1],x)
    else:
        if T[u][2] == -1:
            T[u][2] = len(T)
            T.append([u,-1,-1,x])
        else:
            insert(T,T[u][2],x)
def ino(u):
    if T[u][1] != -1:
        ino(T[u][1])
    ino_res.append(str(T[u][3]))
    if T[u][2] != -1:
        ino(T[u][2])
def pre(u):
    pre_res.append(str(T[u][3]))
    if T[u][1] != -1:
        pre(T[u][1])
    if T[u][2] != -1:
        pre(T[u][2])
def find(u,x):
    if x == T[u][3]:
        return True
    elif x < T[u][3]:
        if T[u][1] == -1:
            return False
        return find(T[u][1],x)
    else:
        if T[u][2] == -1:
            return False
        return find(T[u][2],x)
for c in A:
    if c[0] == 'insert':
        insert(T,0,int(c[1]))
    elif c[0] == 'find':
        print('yes') if find(0,int(c[1])) else print('no')
    else:
        ino_res = []
        ino(0)
        pre_res = []
        pre(0)
        print(' '.join(ino_res))
        print(' '.join(pre_res))
    
