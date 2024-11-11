n,k=map(int,input().split())
x=list(map(int,input().split()))
ans=2*10**8
for i in range(n-k+1):
  ans=min(ans,min(abs(x[i]),abs(x[k+i-1]))+x[k+i-1]-x[i])
print(ans)

