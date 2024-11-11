#!/usr/bin/env python
# -*- coding: utf-8 -*-
import itertools

S = []
N = []
while True:
    n,s = map(int,input().split(" "))
    if s == 0 and n == 0:
        break
    else:
        N.append(n)
        S.append(s)

for i in range(0,len(S)):
    sumMap = list(map(sum,list(itertools.combinations(range(0,S[i]+1),N[i]))))
    print(sum([1 for j in range(0,len(sumMap)) if sumMap[j] == S[i]]))