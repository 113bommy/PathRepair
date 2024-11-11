n,k=map(int,input().split())
h=list(map(int,input().split()))

cost=[10**9]*n
cost[0]=0
for i in range(1,n):
  for j in range(1,min(i+1,k+1)):
    cost[i]=min(cost[i],cost[i-j]+abs(h[i]-h[i-j]))
print(cost[-1])