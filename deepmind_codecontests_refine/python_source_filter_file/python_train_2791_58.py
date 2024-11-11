n,k=map(int,input().split())
h=list(map(int,input().split()))

cost=[0]*n
for i in range(1,n):
  cost[i]=min( [cost[i-j]+abs(h[i]-h[i-j]) for j in range(1,min(i+1,k+1))] )
print(cost[-1])