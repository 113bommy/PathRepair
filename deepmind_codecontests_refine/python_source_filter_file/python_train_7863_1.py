#not done yet

n = int(input())
alist = list(map(int, input().split()))

dp = [[10 for _ in range(4)] for _ in range(n+1)]
for i in range(4):
    dp[0][i] = 0
for i in range(1,n+1):
	dp[i][0] = min(dp[i-1][0], min(dp[i-1][1],dp[i-1][2]))+1
	if alist[i-1] == 1:
		dp[i][2] = min(dp[i-1][0], dp[i-1][1])
	elif alist[i-1] == 2:
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])
	elif alist[i-1] == 3:
		dp[i][1]=min(dp[i-1][2],dp[i-1][0])
		dp[i][2]=min(dp[i-1][1],dp[i-1][0])
		
print(min(dp[n][0],min(dp[n][1],dp[n][2])))