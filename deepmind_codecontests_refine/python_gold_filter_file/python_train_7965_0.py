# -*- coding: utf-8 -*-
"""
Created on Sun Mar 13 11:31:34 2016

@author: kebl4230
"""
import itertools

g = itertools.accumulate

n = int(input())
strengths = [int(num) for num in input().split()]
teams = input()

indexes = [num for num in range(n)]
s2 = [strengths[i] if teams[i] == "B" else 0 for i in indexes]
v = [a - 2*b for a, b in zip(strengths, s2)]
b = sum(s2)
result = b + max(0, max(g(v)), max(g(v[::-1])))
print(result)
