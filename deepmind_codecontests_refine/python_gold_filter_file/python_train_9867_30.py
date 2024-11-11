def main():
	a,b,c,d=map(int,input().split())
	mod=998244353
	dp=[[0 for _ in range(d)]for _ in range(c)]
	dp[a-1][b-1]=1
	for i in range(a-1,c):
		for j in range(b-1,d):
			if i!=a-1:
				dp[i][j]+=dp[i-1][j]*(j+1)%mod
			if j!=b-1:
				dp[i][j]+=dp[i][j-1]*(i+1)%mod
			if i!=a-1 and j!=b-1:
				dp[i][j]-=dp[i-1][j-1]*i*j%mod
			dp[i][j]%=mod
	print(dp[-1][-1])

if __name__ == '__main__':
	main()