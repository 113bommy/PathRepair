A,B,C,D=map(int,input().split())
mod=998244353
dp=[[0]*(C-A+1) for _ in range(D-B+1)]
dp[0][0]=1
for i in range(1,D-B+1):
	dp[i][0]=dp[i-1][0]*A%mod
for j in range(1,C-A+1):
	dp[0][j]=dp[0][j-1]*B%mod
for i in range(1,D-B+1):
	for j in range(1,C-A+1):
		dp[i][j]+=(dp[i-1][j]*(A+j)+dp[i][j-1]*(B+i)-((B+i-1)*(A+j-1))*dp[i-1][j-1]+mod)%mod
print(dp[-1][-1])