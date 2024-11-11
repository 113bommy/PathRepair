# -*- coding: utf-8 -*-
"""
Created on Sun Jan  6 23:10:57 2019

@author: Noussa
"""

a = input()
x = list(map(int,input().split()))
c = 0
s= 0
d = 0
while len(x) != 0:
    if x[0] > x[len(x) -1 ]:
        if c%2 == 0:
            s+= x[0]
        else:
            d+= x[0]
        x.pop(0)
    else:
        if c%2 == 0:
            s+= x[len(x) -1]
        else:
            d+= x[len(x) -1]
        x.pop(len(x) -1)
    
    c += 1
        
print(s,d)
print(x)