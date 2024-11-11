n = int(input())
p = [float(i) for i in input().split()]
dp = [[0 for i in range(len(p)+1)] for j in range(n)]
dp[0][0] = 1 - p[0]
dp[0][1] = p[0]
for i in range(1,n):
	for j in range(len(p)+1):
		dp[i][j] += (1-p[i])*dp[i-1][j]
		dp[i][j] += p[i]*dp[i-1][j-1]
sum1 = 0
for i in dp[n-1][n//2+1:]:
	sum1+=i
print(sum1)