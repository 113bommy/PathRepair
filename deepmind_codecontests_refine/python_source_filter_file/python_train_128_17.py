# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 20:53:20 2021

@author: vukhe
"""

t = int(input())

for i in range(t):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sub = list(set(a).intersection(b))
    
    if len(sub) > 0:
        print("YES")
        print(len(sub), sub[0])
    else:
        print("NO")
