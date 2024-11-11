n, m = map(int, input().split()) 
s = list(map(int, input().split())) 
t = list(map(int, input().split())) 

MOD = 1000000007

dp= [[0] * m for _ in range(n)] 

for i, si in enumerate(s):  
  for j, tj in enumerate(t):
    if i > 0:
      dp[i][j] += dp[i-1][j]
      
    if j > 0:
      dp[i][j] += dp[i][j-1]

    if si == tj:
      dp[i][j] += 1
    elif i > 0 and j > 0:
      dp[i][j] -= dp[i-1][j-1]
    
    dp[i][j] %= MOD

print((dp[n-1][m-1] + 1) % MOD)