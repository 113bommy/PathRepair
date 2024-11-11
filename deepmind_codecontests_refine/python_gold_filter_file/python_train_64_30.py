# -*- coding: utf-8 -*-
"""
Created on Tue Mar  6 23:36:25 2018

@author: Sunny
"""


def RunPrize(n,ar):
    step1=0
    step2=0
    a1=1
    a2=1000000
    for i in range(0,len(ar)):
        if(ar[i]-500000<=0):
            step1+=ar[i]-a1
            a1=ar[i]
        else:
            for j in range(len(ar)-1,i-1,-1):
                step2+=a2-ar[j]
                a2=ar[j]
            break    
    if step1>step2: 
        return step1
    else:
        return step2
        
def hello():
    """Print "Hello World" and return None"""
    n = int(input().strip())
    ar = list(map(int, input().strip().split(' ')))
    
    result=RunPrize(n,ar)
    print(result)
# main program starts here
hello()