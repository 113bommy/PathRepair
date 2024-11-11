# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 01:33:24 2020

@author: Designer
"""
even=0
odd=0
a=int(input(''))
b=str(input('').strip())

for i in range(0,len(b),2): 
    if b[i] == '2':
        even=even+1 
    else:
        odd=odd+1
if  odd == 0:
   print(0)

elif even>odd:
   print(odd)
else:
   c=odd-even
   n=c//3 
   print(even+n)
   