import math as mt 
import sys,string
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
n,m=M()
l=[]
c=0
for i in range(n):
    l.append(list(input().strip()))
    c+=l[-1].count("B")
    
hb=(-1,-1)
for i in range(n):
    for j in range(m):
        if(l[i][j]=="B"):
            hb=(i,j)
            break
lb=(-1,-1)
for i in range(n-1,-1,-1):
    for j in range(m):
        if(l[i][j]=="B"):
            lb=(i,j)
            break
rb=(-1,-1)
for i in range(m-1,-1,-1):
    for j in range(n):
        if(l[j][i]=="B"):
            rb=(i,j)
leftb=(-1,-1)
for i in range(m):
    for j in range(n):
        if(l[j][i]=="B"):
            leftb=(i,j)

s=max(abs(lb[0]-hb[0])+1,abs(rb[1]-leftb[1])+1)
if(s>min(n,m)):
    print(-1)
else:
    print(s**2-c)
        
            
    
