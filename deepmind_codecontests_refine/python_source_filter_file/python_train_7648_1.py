#!/usr/bin/python3.5
import math
mean=[0.0]*200010
real=[0.0]*200010
n,T,c=input().split()
n=int(n)
T=int(T)
c=float(c)
t=T
a=[0]+[int(x) for x in input().split()]
for i in range(1,n+1):
    mean[i]=(mean[i-1]+(a[i]//T))/c
    real[i]=real[i-1]+a[i]

m=int(input())
q=[int(x) for x in input().split()]
for i in range(m):
    r=(real[q[i]]-real[q[i]-t])//T
    ap=mean[q[i]]
    print('{:.6f} {:.6f} {:.6f}'.format(r,ap,math.fabs(ap-r)/r))
