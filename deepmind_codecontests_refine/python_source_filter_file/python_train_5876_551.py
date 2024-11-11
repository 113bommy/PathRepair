# -*- coding: utf-8 -*-
"""
Created on Sun Oct 11 20:37:09 2020

@author: My Family
"""



x=input()
y=input()

x1=[]
y1=[]
y2=[]

for i in x:
    x1.append(ord(i))
    
for j in y:
    y1.append(ord(j))
    

for a in y1[::-1]:
    y2.append(a)




if (x1==y2):
    print("Yes")
else:
    print("NO")