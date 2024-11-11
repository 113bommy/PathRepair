# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 02:17:57 2020

@author: Anshika
"""


t=int(input())

for i in range(t):
    b,p,f=list(map(int,input().split()))
    h,c=list(map(int,input().split()))
    if h>c:
        maxx,minn,maxp,minp=p,f,h,c
    else:
        maxx,minn,maxp,minp=f,p,c,h
    if b//2==0:
        print(0)
    elif b//2 > (p+f):
        print(p*h+f*c)
    elif b//2 > maxx:
        print(maxx*maxp+(b//2-maxx)*minp)
    else:
        print((b//2-maxx)*maxp)
        
        

   


        
