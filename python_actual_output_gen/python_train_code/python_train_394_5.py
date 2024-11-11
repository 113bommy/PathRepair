N,K = map(int,input().split())
LR = [list(map(int,input().split())) for k in range(K)]

dp = (3*N)*[0]
dp[0] = 1
dp[1] = -1

for n in range(N):
  for L,R in LR:
    dp[L+n]+=dp[n]
    dp[n+R+1]-=dp[n]
    dp[n+1] = (dp[n]+dp[n+1])%998244353

print(dp[N-1])