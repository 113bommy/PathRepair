# -*- coding: utf-8 -*-
"""
Created on Wed Sep 16 07:21:31 2020

@author: Harshal
"""


test=int(input())
for _ in range(test):
    x,y,k=map(int,input().split())
    ans=k-(1-y*k-k)//(x-1)
    print(ans)