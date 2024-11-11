# -*- coding: utf-8 -*-
"""
Created on Fri Aug 24 23:13:48 2018

@author: Duy SoCiu
"""

n=int(input())
a=list(map(int,input().split()))
#print(a)
#print(max([sum([a[i]<=a[i-1]*2]for i in range(1,n))]))
ma=1
s=1
if(n==1):
    print(0)
    exit()
for i in range(1,n):
    
    if(a[i]<=a[i-1]*2):
        
        s+=1
        ma=max(ma,s)
        #print(i,ma)
    else:
        s=1
print(ma)