N,M=map(int,input().split())
S=list(map(int,input().split()))
T=list(map(int,input().split()))
mod=1000000007

dp=[[0 for j in range(M+1)] for i in range(N+1)]
Sum=[[0 for j in range(M+1)] for i in range(N+1)]

for i in range(1,N+1):
	for j in range(1,M+1):
		if S[i-1]==T[j-1]:
			dp[i][j]=Sum[i-1][j-1]
#			for k in range(1,i):
#				for l in range(1,j):
#					dp[i][j]+=dp[k][l]
			dp[i][j]+=1
		Sum[i][j]=(Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+dp[i][j])%mod

print(Sum[N][M]+1)