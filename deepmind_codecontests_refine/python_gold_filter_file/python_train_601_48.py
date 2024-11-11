MOD = 10**9+7

N, M=map(int,input().split())
S=list(map(int,input().split()))
T=list(map(int,input().split()))

dp=[[1]*(M+1) for i in range(N+1)]
S_index=[[] for i in range(10**5+1)]

for i in range(N):
  S_index[S[i]].append(i)
  if len(S_index[S[i]])>=2:
    ikkomae=S_index[S[i]][-2]
    for j in range(M+1):
    	dp[i-1][j]=(dp[i-1][j]+dp[ikkomae-1][j])%MOD
  for j in range(M):
    dp[i][j]=dp[i][j-1]
    if len(S_index[T[j]])>=1:
    	dp[i][j]=(dp[i][j]+dp[S_index[T[j]][-1]-1][j-1])%MOD
      
print(dp[N-1][M-1])
