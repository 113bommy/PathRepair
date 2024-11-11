def floor(a,k):
    l=0
    h=len(a)-1
    ans=len(a)
    while l<=h:
        m=(l+h)//2
        if a[m]<=k:
            ans=m
            l=m+1
        else:
            h=m-1
    return ans+1

n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
for i in b:
    print(floor(a,i),end=' ')
