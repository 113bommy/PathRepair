import sys
input=sys.stdin.readline
import copy
from math import *
n=int(input())
a=[-1 for i in range(10)]
for i in range(n):
    p,q=input().split()
    qq=(bin(int(q))[2:])
    q=list((10-len(qq))*"0"+qq)
    if p=='|':
        for i in range(9,-1,-1):
            if  q[i]=='1':
                a[i]=1
    if p=='&':
        for i in range(9,-1,-1):
            if  q[i]=='0':
                a[i]=0
    if p=='^':
        for i in range(9,-1,-1):
            if  q[i]=='1' and (a[i]==0 or a[i]==1):
                a[i]^=1
            elif q[i]=='1' :
                if a[i]==-1:
                    a[i]=-2
                else:
                    a[i]=-1
    #print(a)                
c=0
for i in range(10):
    if a[i]==-2:
        c+=(2**(10-i-1))
print(3)
print("^",c)
v=list("0"*10)
for i in range(10):
    if a[i]==1:
        v[i]='1'
print("|",int("".join(v),2))  
u=list("1"*10)
for i in range(10):
    if a[i]==0:
        u[i]='0'
print("&",int("".join(u),2))  