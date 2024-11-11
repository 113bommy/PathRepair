# -*- coding: utf-8 -*-
"""
#k,m=map(int,input().split())
t=int(input())
for _ in range(t):
    n=int(input())
    x=list(map(int,input().split()))
    
"""
from math import *
t=int(input())
for _ in range(t):
    s=input()
    a=0
    b=0
    c=0
    d=0
    for i in s:
        if i=='L':
            a=a+1
        elif i=='R':
            b=b+1
        elif i=='U':
            c=c+1
        else:
            d=d+1
    x=min(a,b)
    y=min(c,d)
    if x==0 and y==0:
        print(0)
        print()
    elif x==0 and y>0:
        print(2)
        print('UD')
    elif x>0 and y==0:
        print(2)
        print('LR')
    else:
        print(2*(x+y))
        print(x*'R'+y*'U'+1*'L'+(x-1)*'D'+(x-1)*'L'+'D')
        
                
                
                
        
            

                
            
        
        

        
    
    
    

