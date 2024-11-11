#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep  4 21:29:10 2020

@author: suneelvarma
"""

"""
array restoration:
    

5
2 1 49
n x y
5 20 50
6 20 50
5 3 8
9 13 22

1 49 
20 40 30 50 10
26 32 20 38 44 50 
8 23 18 13 3 
1 10 13 4 19 22 25 16 7 

"""

def Search(n, low, high):
    
    arr = []
    limit = (10**9)+1
    for piv in range(low+1,high+1):
        d1,d2 = piv-low, high-piv
        if d2%d1 == 0 and (high-low)//d1 <= n-1:
            break
        
    piv -= low
    
    for num in range(low,high+1,piv):
        if not n: break
        arr.append(num)
        n -= 1
        
    
    for num in range(low-piv, 0, -piv):
        if not n: break
        arr.append(num)
        n -= 1
        
        
    for num in range(high+piv, limit, piv):
        if not n: break
        arr.append(num)
        n -= 1
        
        
    return arr

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n,x,y = tuple(map(int,input().split()))
        print(*Search(n,x,y))