# -*- coding: utf-8 -*-
"""
Created on Mon Jun  8 20:40:29 2020

@author: Anmol Singla
"""


n=int(input())
l=[int(x) for x in input().split()]
mini=min(l)
diff=None
lastmin=None
firstmin=None
for i in range(n):
    if(l[i]==mini):
        if(firstmin==None):
            firstmin=i
            lastmin=i
        else:
            x=i-lastmin-1
            lastmin=i
            if(diff==None):
                diff=x
            else:
                if(diff<x):
                    diff=x
if(diff==None):
    print(mini*n+n-1)
else:
    if(firstmin-lastmin+n-1>diff):
        diff=firstmin-lastmin+n-1
    print(diff+mini*n)