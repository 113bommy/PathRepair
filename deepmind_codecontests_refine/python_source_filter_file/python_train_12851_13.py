import math
n,m=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=math.ceil(a[i]/m)
maxi=a[-1];ind=n
print(a)
for i in range(n-1,-1,-1):
    if maxi<a[i]:
        maxi=a[i]
        ind=i+1
print(ind)

