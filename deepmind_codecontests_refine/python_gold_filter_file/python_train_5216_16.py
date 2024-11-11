from math import *

n=int(input())
m=list(map(int,input().split()))
p=m[0]*2
ans=0
s=1
for i in range(1,n):
    if m[i]<=p:
        s+=1
        p=m[i]*2
    else:
        if s>ans:
            ans=s
        s=1
        p=m[i]*2
print(max(ans,s))