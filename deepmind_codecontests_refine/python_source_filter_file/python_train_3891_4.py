from sys import *
from math import *
n,k=map(int,stdin.readline().split())
a=list(map(int,stdin.readline().split()))
ans=0
for i in range(n-2):
    x=a[i]+k
    l=i+2
    h=n-1
    j=0
    f=0
    while l<=h:
        m=(l+h)//2
        if a[m]>x:
            h=m-1
        elif a[m]<=x:
            j=l
            l=m+1
            f=1
    if f==1:
        y=j-i-2
        ans+=(y+1)*(y+2)//2
print(ans)