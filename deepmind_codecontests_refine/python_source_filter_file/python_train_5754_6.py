from math import *
from collections import *
from random import *
from bisect import *
import sys
input=sys.stdin.readline
t=int(input())
while(t):
    t-=1
    n,k,z=map(int,input().split())
    a=list(map(int,input().split()))
    sc=[]
    pre=[0,a[1]]
    k-=1
    for i in range(2,n):
        pre.append(pre[-1]+a[i])
    for i in range(1,n):
        x=0
        y=k
        zz=z
        tu=0
        while(y>0 and zz>0):
            if(tu%2 ^ 1):
                x+=a[i-1]
            else:
                x+=a[i]
            tu+=1
            y-=1
            if(tu%2==0):
                zz-=1
        if(k<0):
            continue
        if(y==0):
            sc.append(x+a[0]+pre[i])
        else:
            x=x+a[0]+pre[y+1]-pre[i]+pre[i]
            sc.append(x)
        k-=1
    print(max(sc))
        
                
        
    
