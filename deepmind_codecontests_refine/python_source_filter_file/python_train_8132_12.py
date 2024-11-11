# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 14:35:05 2019

@author: avina
"""


n = int(input())

for _ in range(n):
    k,x = map(int, input().strip().split())
    print(k -1 *9 + x)
        