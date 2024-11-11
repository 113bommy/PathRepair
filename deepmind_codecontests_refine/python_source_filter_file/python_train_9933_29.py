n,m=map(int,input().split())
lis=list(map(int,input().split()))
ans=[0]*(n+1)
for i in range(1,n+1):
    ans[i]=ans[i-1]+lis[i-1]
a=1000000000
ind=0
for i in range(m,n):
    if a>ans[i]-ans[i-m]:
        a=ans[i]-ans[i-m]
        ind=i-m+1
print(ind)        
        