import sys
import copy
input=sys.stdin.readline
from math import *
t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(input().rstrip())
    d=a.index(min(a))+1
    p=[]
    for i in range(n):
        if a[i]==min(a):
            p.append(i)
            
    #print(p)
    r=['z' for i in range(n)]
    for i in p:
        if i==n-1:
            s=a[::-1]
        else:   
            if (n-i)%2==0 or i==0:
                s=a[i:]+a[:i]
            else:
                s=a[i:]+a[:i][::-1]
        #print(s,r,s<r)        
        if s<r:
            r=s
            d=i+1
    print("".join(r))
    print(d)