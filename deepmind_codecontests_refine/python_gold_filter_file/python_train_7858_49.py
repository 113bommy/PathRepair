# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 07:01:07 2019

@author: avina
"""

n = int(input())
l = list(map(int, input().split()))
w = 1;i =1
while i < n:
    if l[i] >= l[i-1]:
        k = i-1
        while i < n:
            if l[i] < l[i-1]:
                break
            i+=1
        w = max(i - k,w)
    else:
        i+=1
print(w)
    
        