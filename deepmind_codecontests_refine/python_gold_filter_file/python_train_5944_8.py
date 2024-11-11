# -*- coding: utf-8 -*-
"""
Created on Tue May 28 20:03:18 2019

@author: fsshakkhor
"""

n = input()
ara = list(map(int,input().split()))

for i in range(len(ara)):
    if ara[i] % 2 == 0:
        ara[i] -= 1
        
print(*ara)