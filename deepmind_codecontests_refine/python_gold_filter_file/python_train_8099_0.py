N = int(input())
mod = 10**9+7
dp = [[0]*4 for _ in range(N)]

dp[0] = [1,1,1,1]
dp[1] = [4,4,4,4]
#AGC, ACG, GAC, A?GC,AG?C -> AGGC, ATGC,AGTC

for i in range(2,N):
  if i == 2:
    dp[i][0] = dp[i-1][0]*4
    dp[i][1] = dp[i-1][1]*4-2
    dp[i][2] = dp[i-1][2]*4-1
    dp[i][3] = dp[i-1][3]*4
  else:
    dp[i][0] = sum(dp[i-1])
    dp[i][1] = sum(dp[i-1])-dp[i-2][0]-dp[i-2][2]-dp[i-3][0]*3
    dp[i][2] = sum(dp[i-1])-dp[i-2][0]+dp[i-3][2]
    dp[i][3] = sum(dp[i-1])
    
print(sum(dp[N-1])%mod)
