# -*- coding: utf-8 -*-
"""
Created on Sat Oct 10 17:21:32 2020

@author: My Family
"""

x=0
X = int(input())
z=[]
for i in range(X):
    a=input()
    z.append(a)
    
    
    
    
    
for j in z:
    if (j=="++X" or j=="X++"):
        x+=X
    elif (j=="--X" or j=="X--"):
        x-=X
        
print(x)