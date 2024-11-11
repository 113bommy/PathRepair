#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jun  2 20:52:49 2020

@author: shailesh
"""

def binarySearch(recipe_counts,costs,shop_counts,l, r, R): 
    while l < r-1: 
#        print(l,r)
        mid = (l+r)//2; 
        val = sum([max(0,costs[i]*(recipe_counts[i]*mid -shop_counts[i])) for i in range(3)])
        if val <= R: 
             l = mid
        else: 
            r = mid
      
    return l

recipe = input().strip()
shop_counts = [int(i) for i in input().split()]
costs = [int(i) for i in input().split()]
rem_amt = int(input())

count = 0
recipe_counts = [0,0,0]
for i in recipe:
    if i == 'B':
        recipe_counts[0] +=1
    elif i == 'S':
        recipe_counts[1] += 1
    else:
        recipe_counts[2]+=1
        
r = 10**12
l = 0

ans = binarySearch(recipe_counts,costs,shop_counts,l,r,R=rem_amt)

print(ans)