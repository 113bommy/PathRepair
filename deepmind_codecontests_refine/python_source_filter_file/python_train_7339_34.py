import math as mt 
import sys,string
input=sys.stdin.readline
#print=sys.stdout.write
import random
import collections
from heapq import heappush,heapify,heappop
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
l=[]
for i in range(8):
    s=input()
    s=list(s)
    l.append(s)
x=[]
p=10**10
q=10**10
for i in range(8):

    for j in range(8):
        if(l[j][i]=="B"):
            break
        if(l[j][i]=="W"):
            p=min(p,i)
            break

for i in range(8):
    
    for j in range(7,-1,-1):
        if(l[j][i]=="W"):
            break
        if(l[j][i]=="B"):
            q=min(q,7-j)

if(p<=q):
    print("A")
else:
    print("B")
