# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""


T = int(input())
res = 0
for i in range(T):
    n,s,t = [int(x) for x in input().split()]
    if n==s & n==t:
        res=1
    else:
        res=n-min(s,t)+1
    print (res)