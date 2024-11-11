from collections import *
from math import *


TT=int(input())
for y in range(TT):
    #n=int(input())
    n,m=map(int,input().split())
    #lst=list(map(int,input().split()))
    #s=input()
    x1,y1,x2,y2=map(int,input().split())
    
    w,h=map(int,input().split())
    if ((x2-x1)+w)<=n:
        if ((y2-y1)+h)<=m:
            rh=max(m-y2,y1)
            r1=max(h-rh,0)
            rw=max(n-x2,x1)
            r2=max(w-rw,0)
            
            print(min(r1,r2))
        else:
            rw=max(n-x2,x1)
            r2=max(w-rw,0)
            
            print(r2)
    else:
        if ((y2-y1)+h)<=m:
            rh=max(m-y2,y1)
            r1=max(h-rh,0)
            print(r1)
        else:
            print('-1')