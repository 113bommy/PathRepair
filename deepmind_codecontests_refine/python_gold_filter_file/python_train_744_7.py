# -*- coding: utf-8 -*-
"""
Created on Wed May 20 16:14:12 2020

@author: dell
"""

def round(l):
    t=len(l)
    if t==1 or t==2:
        return 1
    
    i=l.index(1)
    j=l.index(2)        
    #print(i,j)
    if i-j==-1 or i-j== t-1:
        p=j
        q=(p+1)%t
        
        while l[p]-l[q]==-1:
             p=(p+1)%t
             q=(p+1)%t
             
             if q==i:
                 
                 return 1
        else:
            return 0
    
    elif i-j==1:
        p=j
        q=p-1
        
        while l[p]-l[q]==-1:
            
            p=p-1
            q=p-1
            if q==-(t-i):
                return 1
        else:
            return 0
        
    elif i-j== 1-t:
        p=-1
        q=p-1
        
        while l[p]-l[q]==-1:
            p=p-1
            q=p-1
            if q==-(t-i):
                return 1
        else:
            return 0
    


q=int(input())
m=[]
for i in range(q):
    n=int(input())
    l=[x for x in map(int,input().split())]
    if len(l)==n:
        k=round(l)
        m.append(k)
for i in m:
        if i==1:
            print('YES')
        else:
            print('NO')