# -*- coding: utf-8 -*-
"""
Created on Thu Oct 17 18:04:54 2019

@author: sifat_shikdar
"""

def max_min(string):
    res = [-1]*2
    for i in range(0,(len(string))):
        if string[i]=='1':
            res[0]=i
            break
    for i in range((len(string)-1),0,-1):
        if string[i]=='1':
            res[1]=i
            break
    return res
        
        
        
            

t = int(input())

for i in range(t):
    rooms = int(input())
    st = input()
    
    indx = max_min(st)
    if indx[0]==-1 and indx[1]==-1:
        #print(indx)
        print(rooms)
    else:
        print(max((rooms-indx[0])*2,(indx[1])*2))