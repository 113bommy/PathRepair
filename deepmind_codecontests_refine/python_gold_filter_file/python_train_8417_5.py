n=int(input())
s=input()
m=len(s)
mod=10**9+7
dp=[[0]*(n+1) for i in range(n+1)]
dp[0][0]=1
for i in range(1,n+1):
    for j in range(n+1):
        if j==0:
            dp[i][j]+=dp[i-1][j]+dp[i-1][j+1]
        elif j==n:
            dp[i][j]+=dp[i-1][j-1]*2
        else:
            dp[i][j]+=dp[i-1][j-1]*2+dp[i-1][j+1]
        dp[i][j]%=mod
def div(a,b):
    return (a*pow(b,mod-2,mod))%mod
print(div(dp[n][m],pow(2,m)))