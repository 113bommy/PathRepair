# -*- coding: utf-8 -*-
"""
Created on Tue Nov 26 16:43:27 2019

@author: 93464
"""

n = int(input())
asd = [int(x) for x in input().split()]
ccc=1
ddd=0
eee=1
while ddd<len(asd)-1:
    if asd[ddd]<=asd[ddd+1]:
        ccc = ccc+1
    else:
        if ccc>eee:
            eee = ccc
        else:
            eee = eee
            ccc=1
    ddd=ddd+1
if ccc>eee:
    eee = ccc
else:
    pass
print(eee)