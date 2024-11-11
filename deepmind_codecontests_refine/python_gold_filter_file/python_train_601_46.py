n,m=map(int,input().split())
s=input().split()
t=input().split()
dp=[[1]*(m+1)]+[[1]+[0]*m for _ in range(n)]
for i in range(n):
	for j in range(m):
		dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1]-dp[i][j]*(s[i]!=t[j]))%(10**9+7)
print(dp[-1][-1])