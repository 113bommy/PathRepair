import collections
N,K=map(int,input().split())
#N=int(input())
A=list(map(int,input().split()))
M=10**9+7
dp=[[0]*(K+2)for i in range(N+1)]
for i in range(N+1):
    dp[i][0]=1

for i in range(1,A[0]+1):
    dp[0][i]=1
for i in range(N-1):
    for j in range(K+1):
        if j-A[i+1]<0:
            dp[i+1][j+1] = (dp[i+1][j]+dp[i][j+1])%M
        else:
            dp[i+1][j+1] = (dp[i+1][j]+dp[i][j+1]-dp[i][j-A[i+1]])%M
print(dp[N-1][K])