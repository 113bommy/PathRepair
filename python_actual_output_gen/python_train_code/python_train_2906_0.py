# -*- coding: utf-8 -*-
"""
Created on Fri Jul  3 17:27:38 2020

@author: Pooja Patidar
"""

for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()[:2*n]))
    b=[]
    for i in a:
        if i not in b:
            b.append(i)
    print(b)

    

    
    