#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  1 18:48:05 2020

@author: shailesh
"""

n,m = [int(i) for i in input().split()]


ans = pow(3,n,m) - 1

if ans == -1:
    ans = m-1

print(m)