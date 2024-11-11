from math import ceil
n,k=map(int,input().split())
mid=ceil(n/2)
if k<=mid:
    print(k*2-1)
else:
    k//=2
    print(2*k)