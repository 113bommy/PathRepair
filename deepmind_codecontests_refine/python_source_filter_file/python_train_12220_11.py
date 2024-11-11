import math as mt 
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
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
x,y=M()
d=defaultdict(int)
a,b=0,0
d[(0,0)]=0
l=1
c=0
while(l<102):
    for t in range(l):
        d[(a+1,b)]=c
        a+=1
    c+=1
    for t in range(l):
        d[(a,b+1)]=c
        b+=1
    c+=1
    l+=1
    for t in range(l):
        d[(a-1,b)]=c
        a-=1
    c+=1
    for t in range(l):
        d[(a,b-1)]=c
        b-=1
    c+=1
    l+=1
print(d[(x,y)])
