#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 02:37:25 2020

@author: maruf
"""
#(list_1[i]==t and list_1[i+1]==t)                          #condition 2


s=input()
t='-'
p='.'
i=0
list_1=list(s)

list_2=[]

while(i<len(s)):
    if (list_1[i] == t):
        if (list_1[i]==t and list_1[i+1]==p):
            list_2.append(1)
            i+=1
        else :
            list_2.append(2)
            i+=1
       # i+=1  
    else:
            list_2.append(0)
    i+=1        

print(list_2)  
print(''.join(map(str, list_2)))
          
            
            
            
            
            
            