#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 13 16:55:27 2020

@author: dennis
"""

t = int(input())
for _ in range(t):
    li = [int(x) for x in input().split()]
    li.sort()
    if li[-1] > (li[0]+li[1]+2):
        print('No')
    else:
        print('Yes')
