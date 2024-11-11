import math
n=int(input())
a=list(map(int,input().split()))
a.sort()
b=0
c=0

s=sum(a[:n//2])
t=sum(a[n//2:])
r=int(s*s+t*t)

