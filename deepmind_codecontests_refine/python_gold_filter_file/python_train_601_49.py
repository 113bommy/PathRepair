n,m=map(int,input().split())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
mod=10**9+7
dp=[[0]*(m+1) for i in range(n+1)]
total=[[0]*(m+1) for i in range(n+1)]
for i in range(n):
	for j in range(m):
		if s[i]==t[j]:
			dp[i+1][j+1]=(total[i][j]+1)%mod
		total[i+1][j+1]=(total[i+1][j]+total[i][j+1]-total[i][j]+dp[i+1][j+1])%mod
print((total[-1][-1]+1)%mod)