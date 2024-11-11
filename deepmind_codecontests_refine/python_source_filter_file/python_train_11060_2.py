#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May  3 17:02:53 2020

@author: neb0123
"""

def max_overlap(start, end):
    n = len(start)
 
    start.sort()
    end.sort()
 
    inter = 1
    max_inter = 1
    i = 1
    j = 0
    while i < n and j < n:
        if start[i] <= end[j]:
            inter += 1
            if inter > max_inter:
                max_inter = inter
            i += 1
        else:
            inter -= 1
            j += 1
 
    return max_inter
  

def solution(A, n, k):
    arrl = []
    ext = []
    
    for i in range(n // 2):
        x, y = A[i], A[-i-1]
        arrl.append(1 + min(x,y))
        ext.append(k + max(x,y))
        arrl.append(x+y)
        ext.append(x+y)
        
    x = max_overlap(arrl, ext)
    
    return n - x
        

if __name__ == "__main__":
    # inputs = input()
    # string = str(inputs)
    # map(int, input().split(" "))
    
    t = int(input())
    
    for _ in range(t):
        n, k = map(int, input().split(' '))
        A = list(map(int, input().split(' ')))

    print(solution(A,n,k))
