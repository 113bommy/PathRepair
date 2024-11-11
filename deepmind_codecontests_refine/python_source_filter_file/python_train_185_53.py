# -*- coding: utf-8 -*-
"""
Created on Mon Dec 31 14:30:45 2018

@author: Yamazaki Kenichi
"""

N,P = map(int, input().split())

limit = int(pow(P,1/N)//1)

if N == 1:
    ans = P
elif limit == 1:
    ans = 1
else:
    ans = 1
    for i in range(2,limit+1):
        if P % pow(i,N) == 0:
            ans = i
            
print(ans)
