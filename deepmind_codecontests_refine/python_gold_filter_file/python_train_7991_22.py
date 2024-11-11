import math

n,k=map(int,input().split())

A=list(map(int,input().split()))

low=1
high=max(A)

while low!=high:
    mid=(low+high)//2
    s=0
    for i in range(n):
        s+=math.ceil(A[i]/mid)-1
    if s>k:
        low=mid+1
    else:
        high=mid


print(low)