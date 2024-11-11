import math
n,k=map(int,input().split())
a=list(map(int,input().split()))
x0=0
x1=10**9
while(1):
    sum=0
    mid=(x0+x1)//2
    for i in range(n):
        sum+=math.ceil(a[i]/mid)-1
    if(sum<=k):
        x1=mid
    if(sum>k):
        x0=mid
    if(x0+1==x1):
        print(x1)
        break