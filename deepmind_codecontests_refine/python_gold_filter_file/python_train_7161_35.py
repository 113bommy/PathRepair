N,T=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(N)]
#dp[i][j] 料理iまでの間で、時間jまでに達成できる最大効用
dp=[[0]*(T+1) for _ in range(N+1)]
AB.sort()
for i in range(1,N+1):
  dp[i]=dp[i-1][:]
  time=AB[i-1][0]
  happy=AB[i-1][1]
  for j in range(T):
    dp[i][min(j+time,T)]=max(dp[i][min(j+time,T)],dp[i-1][j]+happy)
print(dp[N][T])
    