from math import *
l,r,d=map(int,input().split())

c=(l-1)//d
k=r//d
ans=k-c
print(ans)