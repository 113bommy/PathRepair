N = int(input())
*p,= map(float,input().split())
dp = [[0]*(N+1) for _ in range(N+1)]
dp[0][0] = 1

for i in range(N):
	dp[i+1][0] = dp[i][0]*(1-p[i])
	
for i in range(N):
	for h in range(N):
		dp[i+1][h+1] = dp[i][h+1]*(1-p[i]) + dp[i][h]*p[i]

print(sum(dp[-1][N//2+1:]))