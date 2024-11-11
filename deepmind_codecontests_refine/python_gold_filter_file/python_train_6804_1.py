#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug  4 19:41:21 2020

@author: divyarth
"""

import sys
import heapq
import math

#sys.setrecursionlimit(100000)
#input=sys.stdin.readline
#print=sys.stdout.write

from collections import deque
from collections import defaultdict
from collections import Counter

modH=int(10**9)+7
I=lambda : list(map(int,input().split(' ')))
def PRINT(lst,sep=' '): print(sep.join(map(str,lst)))

n,k=I()
lst=I()
lst.sort()
cum_sum=[0]

for i in range(len(lst)): cum_sum.append(cum_sum[-1]+lst[i])
def SUM(start,end):
    return cum_sum[end+1]-cum_sum[start]

def binSearch(end,k,elem):
    left=0
    right=end
    best=None
    while left<=right:
        mid=(left+right)//2
        if SUM(mid,end)+k>=(end-mid+1)*elem:
            best=mid
            right=mid-1
        else:
            left=mid+1
    return best
        

if k+SUM(0,len(lst)-1)>=lst[-1]*len(lst):
    print(len(lst),end=' ')
    print(lst[-1])
else:
    best=lst[0]
    nums=1
    for i in range(1,len(lst)):
        bb=binSearch(i-1,k,lst[i])
        if bb!=None and i-bb+1>nums:
            best=lst[i]
            nums=i-bb+1
            
    print(nums,end=' ')
    print(best)
    