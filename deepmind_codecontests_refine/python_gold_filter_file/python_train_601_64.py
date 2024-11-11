#common subsequence
n,m=map(int,input().split())
mod=10**9+7
a=list(map(int,input().split()))
b=list(map(int,input().split()))
dp=[[0 for i in range(m+1)] for j in range(n+1)]
#dp[i][j]=aのi番目、bのj番目まででの個数
#求めたいのはdp[n][m]
for i in range(m+1):
    dp[0][i]=1
for i in range(n+1):
    dp[i][0]=1
dp[0][0]=1
for i in range(1,n+1):
    for j in range(1,m+1):
        if a[i-1]==b[j-1]:
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod
        else:
            dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1])%mod
print(dp[n][m])