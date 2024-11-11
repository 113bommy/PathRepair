# -*- coding: utf-8 -*-
"""
Created on Fri Dec 27 20:15:26 2019

@author: HP
"""

for i in range(int(input())):
    x,y,z=input().split()
    p=int(x)
    q=int(y)
    r=int(z)
    l=[p,q,r]
    l.sort()
    sub=l[-1]-(l[0]+l[1])
    if sub<3:
        print("Yes")
    else:
        print("No")