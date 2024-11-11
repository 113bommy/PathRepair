# -*- coding: utf-8 -*-
"""
Created on Thu Dec 12 16:11:15 2019

@author: Mridul Garg
"""

q = int(input())
#q = 1
for _ in range(q):
    n = int(input())
    p = list(map(int, input().split(' ')))
    
    if n < 10:
        print(0, 0, 0)
        continue
    
    g = 0
    for i in range(n-1):
        if p[i] > p[i+1]:
            g = 1+i
            break
    
#    print(g)
    
    i = g
    s = 0
    ans = 1
    while True:
#        print(s, i)
        if i == n-1:
            ans = 0
            break
        
        elif s > g:
            if p[i] > p[i+1]:
                break
            else:
                s += 1
                i += 1
        
        else:
            s += 1
            i += 1
            
    if ans == 0:
        print(0, 0, 0)
        continue        
    
    if n%2 == 0:
        mid = (n-1)//2
    else:
        mid = (n-1)//2 - 1
        
    b = 0
#    print()
#    print(mid, i)
#    print()
    for j in range(mid, i-1, -1):
#        print(mid, p[j], p[j+1])
        if p[j] > p[j+1]:
            b = j - i + 1
            break
            
#    print(g, s, b)
    
    if g < b:
        print(g, s, b)
        
    else:
        print(0,0,0)
    
    
        
        
    
    
            
            
        
        
        