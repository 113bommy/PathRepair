# -*- coding: utf-8 -*-
"""
Created on Mon Jan  8 09:03:34 2018

@author: yanni
"""

k, n = [int(x) for x in input().split()]
power = 1
while (power <= k):
    power *= 2
if (k == 1):
    print(n)
else:
    print(power-1)