# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
n,m = map(int, input().split(" "))
s = str(input())
s = list(s)
for i in range(m):
    l,r,c1,c2 = map(str, input().split(" "))
    for j in range(int(l)-1,int(r)):
        if s[j] == c1:
            s[j] = c2
for i in range(len(s)):
    print(s[i], end = " ")