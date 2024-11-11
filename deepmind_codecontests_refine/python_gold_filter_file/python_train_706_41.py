mod=10**9+7
N,K=map(int,input().split())
a = list(map(int,input().split()))
ans=[[0 for e in range(K+1)] for f in range(N+1)]
for e in range(K+1):
 ans[1][e]=min(e+1,a[0]+1)
if N>1:
 for i in range(2,N+1):
  ans[i][0]=1
  for j in range(1,K+1):
   ans[i][j]=ans[i][j-1]+ans[i-1][j]
   if j-a[i-1]-1>=0:
    ans[i][j]-=ans[i-1][j-a[i-1]-1]
   ans[i][j]%=mod
if K==0:
 print(ans[N][K])
else:
 print((ans[N][K]-ans[N][K-1])%mod)
    