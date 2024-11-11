# -*- coding: utf-8 -*-
"""
Created on Wed Apr 22 09:02:40 2020

@author: vicen
"""

n = int(input())

t = list(map(int, input().split()))
t.sort()

time = 0
happy = 0

for i in t:
  if time <= i:
    happy += 1
    time += i

print(happy)