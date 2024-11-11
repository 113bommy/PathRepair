# -*- coding: utf-8 -*-
"""
Created on Sat Oct 24 15:37:45 2020

@author: Ngo-Manh.Tuan
"""

n = int(input())
interesting = list(map(int, input().split(' ' )))

start = 0
watch = 0
count = 0
for i in interesting:
    if i - start < 15:
        watch = i
        start = i
    else:
        break

print(min(90, watch + 15))