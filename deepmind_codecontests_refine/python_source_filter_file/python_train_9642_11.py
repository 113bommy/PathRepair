# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 14:04:16 2020

@author: prana
"""

n=int(input())
s=input()

if s[0]=="F":
    print("NO")
elif s[0]==s and s[n-1]==s:
    print("NO")
else:
    print("YES")