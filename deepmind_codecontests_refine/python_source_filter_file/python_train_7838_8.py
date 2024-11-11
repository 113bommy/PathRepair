# -*- coding: utf-8 -*-
"""
Created on Thu May 21 08:50:19 2020

@author: Harshal
"""

import sys
n=int(input())
arr=list(map(int,input().split()))
arr.sort(reverse=True)
ans=0
c=0
if n==0:
    print(0)
    sys.exit()
for i in arr:
    ans+=i
    c+=1
    if ans>=n:
        print(c)
        sys.exit()
        break
print(c)  
        