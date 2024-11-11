N,M=map(int,input().split())
broken=[0]*N
for _ in range(M):
  a=int(input())
  broken[a]=1
dp=[0]*(N+2)
dp[N]=1
for i in range(N-1,-1,-1):
  if broken[i]==1:
    dp[i]=0
  else:
    dp[i]=(dp[i+1]+dp[i+2])%1000000007
print(dp[0])