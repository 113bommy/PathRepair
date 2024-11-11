# -*- coding: utf-8 -*-
"""
Created on Mon Jul 20 01:21:37 2020

@author: thiva
"""

n,k = map(int, input().split())
Fences = [int(s) for s in input().split()]
net = 0
pos = 1
minimum = 0

for i in range(n-k):
    L = Fences[i]
    R = Fences[i+k]
    net = net + R - L
    
    if(net < minimum):
        minimum = net
        pos = i+2
print(pos)
