mod=998244353
n,s=map(int,input().split())
a=list(map(int,input().split()))
dp=[[0 for j in range(s+1)] for i in range(n)]
dp[0][0]=2
if a[0]<=s: dp[0][a[0]]=1

for i in range(1,n):
    for j in range(s+1):
        dp[i][j]+=dp[i-1][j]*2
        if j-a[i]>=0: dp[i][j]+=dp[i-1][j-a[i]]
        dp[i][j]%=mod
print(dp[n-1][s])