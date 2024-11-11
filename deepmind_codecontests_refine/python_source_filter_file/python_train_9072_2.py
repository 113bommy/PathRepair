# -*- coding: utf-8 -*-
"""
Created on Sat Jun  8 23:43:22 2019

@author: Hamadeh
"""

# -*- coding: utf-8 -*-
"""
Created on Sat Jun  8 23:34:53 2019

@author: Hamadeh
"""
from math import ceil
class cinn:
    def __init__(self):
        self.x=[]
    def cin(self,t=int):
        if(len(self.x)==0):
            a=input()
            self.x=a.split()
            self.x.reverse()
        return self.get(t)
    def get(self,t):
        return t(self.x.pop())
    def clist(self,n,t=int): #n is number of inputs, t is type to be casted
        l=[0]*n
        for i in range(n):
            l[i]=self.cin(t)
        return l
    def clist2(self,n,t1=int,t2=int,t3=int,tn=2):
        l=[0]*n
        for i in range(n):
            if(tn==2):
                a1=self.cin(t1)
                a2=self.cin(t2)
                l[i]=(a1,a2)
            elif (tn==3):
                a1=self.cin(t1)
                a2=self.cin(t2)
                a3=self.cin(t3)
                l[i]=(a1,a2,a3)
        return l
    def clist3(self,n,t1=int,t2=int,t3=int):
        return self.clist2(self,n,t1,t2,t3,3)
    def cout(self,i,ans=''):   
        if(ans==''):
            print("Case #"+str(i+1)+":", end=' ')
        else:
            print("Case #"+str(i+1)+":",ans)
    def printf(self,thing):
        print(thing,end='')
    def countlist(self,l,s=0,e=None):
        if(e==None):
            e=len(l)
        dic={}
        for el in range(s,e):
            if l[el] not in dic:
                dic[l[el]]=1
            else:
                dic[l[el]]+=1
        return dic
    def talk (self,x):
        print(x,flush=True)
    def dp1(self,k):
        L=[-1]*(k)
        return L
    def dp2(self,k,kk):
        L=[-1]*(k)
        for i in range(k):
            L[i]=[-1]*kk
        return L
c=cinn()
x=c.cin()
size=ceil(x/2)
print(size)
for i in range(1,x+1):
    print((i//2)+1,ceil(i/2))