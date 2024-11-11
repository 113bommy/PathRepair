from sys import *
from math import *
t=int(stdin.readline())
for _ in range(t):
    n,k=map(int,stdin.readline().split())
    a=list(map(int,stdin.readline().split()))
    x=a[0]
    y=0
    b=[]
    for i in range(1,n):
        if a[i]>x and y==0:
            x=a[i]
        if a[i]<x and y==0:
            y=a[i]
        if a[i]<y:
            y=a[i]
        if a[i]>x and y!=0:
            b.append(x)
            b.append(y)
            x=a[i]
            y=0
    b.append(x)
    ans=0
    f=0
    for i in range(len(b)):
        if f==0:
            ans+=b[i]
            f=1
        elif f==1:
            ans-=b[i]
            f=0
    print(ans)
