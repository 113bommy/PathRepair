# -*- coding: utf-8 -*-
"""
Created on Thu Jun  4 21:32:52 2020

@author: user
"""
import sys
input=sys.stdin.readline
output=sys.stdout
def inlt():
    return(list(map(int,input().split())))
def solve(n,l):
    res=-1
    set1=set(l)
    list1=[]
    for i in range(1,max(l)+1):
        list1=[]
        for j in range(n):
            list1.append(l[j]^i)
        if(set1==set(list1)):
            res=i
            break
    output.write(str(res)+'\n')
    
t=int(input())
for i in range(t):
    n=int(input())
    l=inlt()
    solve(n,l)