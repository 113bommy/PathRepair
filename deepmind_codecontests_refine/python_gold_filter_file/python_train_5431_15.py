import math as mt 
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
from decimal import *
getcontext().prec = 100
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())

def dist(x,y,c,d):
    return (x-c)**2+(y-d)**2
def circle(x1, y1, x2,y2, r1, r2): 
    distSq = (((x1 - x2)* (x1 - x2))+ ((y1 - y2)* (y1 - y2)))**(.5)   
    if (distSq + r2 <= r1): 
        return True
    else: 
        return False
    print(c[i][1],end=" ")
        
               
n=I()
p=[]
w=[]
s=[]
ssum=0
wsum=0
psum=0
for i in range(n):
    k=float(input())
    if(int(k)==k):
        s.append([int(k),i])
        ssum+=int(k)
    elif(k>0):
        p.append([int(k),i])
        psum+=int(k)
    else:
        w.append([int(k),i])
        wsum+=int(k)

q=ssum+wsum+psum
if(q>0):
    for i in range(0,q):
        w[i][0]-=1
else:
    q=-q
    for i in range(0,q):
        p[i][0]+=1
    
e=s+p+w
e.sort(key=lambda x:x[1])
for i in range(n):
    print(e[i][0])
