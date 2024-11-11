#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec 14 10:02:45 2018

@author: umang
"""

n = int(input())
a = list(map(int, input().split()))
max_num = max(a)

x = 1
        
energy = 0

#print(x)
    
for i in range(len(a)):
    energy += (x + i + abs(x-i)) * a[i] # up
#    print("energy up for floor:", str(i+1), ":", (x+i+abs(x-i)) * a[i])
    energy += (abs(i-x) + i + x) * a[i] # down
#    print("energy down for floor:", str(i+1), ":", (abs(i-x) + i + x) * a[i])
    
print(energy)