n,k=map(int,input().split())
x=list(map(int,input().split()))
ans=1000000
for i in range(n+1-k):
  ans=min(ans,x[i+k-1]-x[i]+min(abs(x[i]),abs(x[i+k-1])))
print(ans)