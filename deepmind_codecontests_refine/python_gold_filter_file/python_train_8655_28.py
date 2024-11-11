# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 23:38:51 2019

@author: avina
"""

s = input().strip()

k = 0
d = len(s)
for i in range(d):
    if s[i] == 'a':
        k+=1

if k > d//2 or k > d//2 +1:
    print(d)
else:
    print(2*k - 1)
    