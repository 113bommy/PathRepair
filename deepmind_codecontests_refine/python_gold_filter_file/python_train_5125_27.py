# -*- coding: utf-8 -*-
"""
Created on Sat Feb 22 17:25:01 2020

@author: hp
"""

t = int(input())
l =[]
for i in range(t):
    que = [int(j) for j in input().strip().split()]
    n = que[0]
    d = que[1]
    lst = [int(j) for j in input().strip().split()]
    Sum = lst[0]
    for i in range(1,len(lst)):
        if(lst[i]):
            MAX = int(d/i)
            if(MAX>=lst[i]):
                d = d-lst[i]*i
                Sum = Sum +lst[i]
            else:
                d = d-MAX*i
                Sum = Sum + MAX
                break;
    l.append(Sum)
for i in l:
    print(i)
        
        
                
                
                
            