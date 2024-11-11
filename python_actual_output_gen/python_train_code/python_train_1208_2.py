# -*- coding: utf-8 -*-
"""
Created on Thu Aug  6 18:44:07 2020

@author: kais
"""
nn=input()
nn=nn.split()
n=int(nn[0])
m=int(nn[1])
di=dict()
for i in range(n):
    k=input()
    k=k.split()
    mm=k[0]
    l=k[1]
    kk=l+';'
    di[kk]=mm
print(di)
for i in range(m):
    j=input()
    j=j.split()
    jj=j[0]
    h=j[1]
    
   
    print (jj,h,'#'+str(di[h]))