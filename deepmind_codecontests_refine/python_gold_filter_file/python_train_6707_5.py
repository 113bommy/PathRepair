# -*- coding: utf-8 -*-
"""
Created on Tue Feb  4 15:17:49 2020

@author: DeLL
"""

s=input()
n=int(((s.count('n'))-1)/2)
i=s.count('i')
e=int((s.count('e'))/3)
t=s.count('t')
print(min(n,i,e,t))