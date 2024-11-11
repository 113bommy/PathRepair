#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 29 19:22:29 2018

@author: ska

967-B
"""

n,a,b = map(int, input().split())
ar = list(map(int, input().split()))
su = sum(ar)
ark = ar.pop(0)
ar.sort(reverse=True)
if (ark/su)*a >= b:
    print(0)
else:
    flag =0
    br = [ar[0]]
    for i in range(1,n-1):
        br.append(br[-1]+ar[i])
    for i in range(n-1):
        if (ark*a)/(br[i]+ark) >= b:
            print(i+1)
            flag =1
            break
    if flag ==0:
        print(n-1)
    



