def sol(a):
    a+=m
    
    for i in range(n):
        x=aa[i]
        if i==n-1:
            y=bb[0]
        else:
            y=bb[i+1]
        a-=(a/x)
        if a<0:
            return -1
        a-=(a/y)
        if a<0:
            return -1
    return a-m
n=int(input())
m=int(input())
aa=list(map(int,input().split()))
bb=list(map(int,input().split()))
low=0
high=10**9
ep=10**(-8)
ans=-1
while low<high:
    mid=(low+high)/2
    left=sol(mid)
    #print(mid,left)
    if left<0:
        low=mid
        continue
    if left<ep:
        ans=mid
        break
    else:
        high=mid
print(ans)
