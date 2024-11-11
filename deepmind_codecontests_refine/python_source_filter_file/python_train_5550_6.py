#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  1 20:47:44 2020

@author: divyarth
"""

import sys
import heapq
import math
sys.setrecursionlimit(100000)

from collections import deque
from collections import defaultdict
from collections import Counter

#input=sys.stdin.readline
#print=sys.stdout.write

def PRINT(lst,sep=' '): print(sep.join(map(str,lst)))
I=lambda : list(map(int,input().split(' ')))

def solve(lst):
    n=len(lst)
    nn=n//2
    ll=[(ele,i+1) for i,ele in enumerate(lst)]
    ll.sort()
    x=[]
    y=[]
    sy=0
    sx=0
    while max(len(x),len(y))<(nn if n%2==0 else nn+1) and len(ll)>0:
        
        val,name=ll.pop()
        sx+=val
        x.append(name)

        while max(len(x),len(y))<(nn if n%2==0 else nn+1) and len(ll)>0 and sx>sy:
            val,name=ll.pop()
            sy+=val
            y.append(name)
    
    def fill(arr):
        while ll:
            s,_=ll.pop()
            arr.append(s)
            
    if n%2==0:   
        if len(x)==nn:
            fill(y)
        if len(y)==nn:
            fill(x)
    elif n%2==1:
        if len(x)==nn+1:
            fill(y)
        if len(y)==nn+1:
            fill(x)
            
    
        
            
    print(len(x))
    PRINT(x)
    print(len(y))
    PRINT(y)
    
    return


n=int(input())
lst=I()
solve(lst)