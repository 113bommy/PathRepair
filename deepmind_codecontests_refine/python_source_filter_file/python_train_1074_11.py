from math import *
n=int(input())
arr=list(map(int,input().split()))
arr.sort()
ans=0
for i in range(n-1,-1,-2):
    if(i==0):
        ans+=pi*arr[0]
    else:
        ans+=pi*(arr[i]**2-arr[i-1]**2)
print(round(ans,10))