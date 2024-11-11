#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul 31 12:49:50 2020

@author: shailesh
"""

def bin_search(n):
    if n==1:
        return 1
    l = 0;r = n;
    while(r - 1 > l):
#        print(l,r)
        mid = (l+r)//2
        
        val = mid*(mid+1)//2
        if val == n:
            return mid
        elif val > n:
            r = mid - 1
        else:
            l = mid + 1
    
    return l


n,k = [int(i) for i in input().split()]

if k*(k-1)//2 < n - 1:
    print(-1)

elif n == 1:
    print(0)
elif n <= k:
    print(1)
    
else:
    print(k - 1 - bin_search(k*(k-1)//2 - n + 1))