# -*- coding: utf-8 -*-
"""
Created on Wed Apr 14 23:12:10 2021

@author: sumanthsetty
"""


for i in range(int(input())):
    
    n = int(input())
    
    
    a = []
    ar = []
    
    indexes = []
    
    for p in range(n):
        
        a = input()
        
        if "*" in a:
            indexes.append(p)
            
        
        ar.append(a)
    
    indexes_in = []
    
    for p in indexes:
        for q in range(n):
            
            if ar[p][q]=="*":
                indexes_in.append(q)
    
    p1 = []
    p2 = []
    if len(indexes)==1:
        p1.append((indexes[0]+1)%n)
        p1.append(indexes_in[0])
        p2.append((indexes[0]+1)%n)
        p2.append(indexes_in[1])
    
        
    elif indexes_in[0]==indexes_in[1]:
        p1.append(indexes[0])
        p1.append((indexes_in[0]+1)%n)
        p2.append((indexes[0]))
        p2.append((indexes_in[1]+1)%n)
                
    else:
        p1.append(indexes[0])
        p1.append(indexes_in[1])
        p2.append(indexes[1])
        p2.append(indexes_in[0])
        
    ar[p1[0]] = ar[p1[0]][:p1[1]]+"*"+ar[p1[0]][p1[1]+1:]
    ar[p2[0]] = ar[p2[0]][:p2[1]]+"*"+ar[p2[0]][p2[1]+1:]
    
    for p in ar:
        print(p)
        
    
        
        
    