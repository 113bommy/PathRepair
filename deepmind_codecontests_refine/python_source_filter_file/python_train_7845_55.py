# -*- coding: utf-8 -*-
"""
Created on Fri Oct 30 16:45:22 2020

@author: qzb11
"""

i = int(input());
for n in range(i):
    angle = int(input());
    x = 360 / (180 - angle)
    if int(x) == x:
        print('Yes')
    else:
        print('No')