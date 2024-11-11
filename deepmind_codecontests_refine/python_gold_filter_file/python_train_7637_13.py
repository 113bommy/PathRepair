from math import *
n=int(input())
l=[0]*(n+1)
for i in range(0,n):
    l[i]=int(input())
t=l[0]+1
for i in range(1,n):
    t+=abs(l[i]-l[i-1])+2
print(t)