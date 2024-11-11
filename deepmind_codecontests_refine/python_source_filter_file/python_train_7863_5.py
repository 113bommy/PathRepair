n = int(input())

l = list(map(int,input().split()))

dp = [[0,0,0] for i in range(n+1)]

for i in range(1,n+1):

	dp[i][0] = max(dp[i-1])

	if l[i-1] == 3:
		dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1)
		dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1)
	elif l[i-1] == 2:
		dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1)
	elif l[i-1] == 1:
		dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1)
print(dp)
print(n-max(dp[n]))
