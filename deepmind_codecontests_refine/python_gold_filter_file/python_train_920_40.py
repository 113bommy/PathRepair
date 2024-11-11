n,x=map(int,input().split())
arr=list(map(int,input().split()))
cost=[10**18]*n
ans=10**18
for i in range(n):
  for j in range(n):
    cost[j]=min(cost[j],arr[j-i])
  ans=min(ans,x*i+sum(cost))
print(ans)