n,b=map(int,input().split())
a=list(map(int,input().split()))
cur_max=[0]*(n+1)
ans=0
for i in range(n-1,-1,-1):
    cur_max[i]=max(a[i],cur_max[i+1])
for i in range(n-1):
    ans=max(ans,b//a[i]*cur_max[i]+b%a[i])
print(ans)
