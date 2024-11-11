# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 21:52:02 2018

@author: Duy SoCiu
"""

def a():
    n=int(int(input()))
    if(n==1):
        print('YES')
        return
    a=input()
    b=list(set(a))
    c=sum(a.count(b[i])>1 for i in range(len(b)))
    #d=sum(a.count(b[i])==1 for i in range(len(b)))
    print(['NO','YES'][c>0])
a()