# -*- coding: utf-8 -*-
"""
Created on Sat May  9 15:58:30 2020

@author: Kashem Pagla
"""


n=int(input())
l=list(map(int, input().split()))[:n]
a=l.count(0);b=l.count(5);c=0;d=-1

while (b>=1 and a>=1):
    c=int(str(5)*b+str(0))
    if(c%90==0):
        d=c 
        break
    b-=1
    
if(d>0):    
    if(d>0 and a>1): 
        d=int(str(c)+"0"*(a-1))
        print(d)
    else: print(d)
elif(a>0 and d==-1):
    print(0)
else: print(d)           
    