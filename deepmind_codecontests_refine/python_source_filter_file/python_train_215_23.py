from sys import *
from math import *
n,k=map(int,stdin.readline().split())
a=list(map(int,stdin.readline().split()))
a.sort()
p=n//2
if a[p]==k:
    print(0)
else:
    if a[p]>k:
        x=-1
    else:
        x=1
    ans=0
    for i in range(n//2+1):
        if x==1:
            if a[p-i]>k:
                ans+=abs(a[p-i]-k)
        if x==-1:
            if a[p+i]<k:
                ans+=abs(a[p+i]-k)
    print(ans)