# -*- coding: utf-8 -*-
"""
Created on Fri Mar  9 18:36:20 2018

@author: hp
"""

n = eval(input())
a = [eval(x) for x in str.split(input())]
x = sum(a) /  2

alice = 0
total = 0

while (total <= x):
    if total + a[alice] <= x / 2:
        total += a[alice]
        alice += 1
    elif total <= x - total - a[alice]:
        total += a[alice]
        alice += 1        
    else:
        break
            
print(alice,n - alice)