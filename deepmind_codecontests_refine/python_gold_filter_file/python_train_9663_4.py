s=input()
abc="ABCD"
n=len(s)
mod=10**9+7
dp=[[0]*4 for i in range(n+1)]
dp[n][3]=1
for i in range(n-1,-1,-1):
    for j in range(4):
        if s[i]=='?' :
            if j==3:
                dp[i][j]=3*dp[i+1][j]
            else :
                dp[i][j]=3*dp[i+1][j]+dp[i+1][j+1]
        elif s[i]==abc[j]:
            if j!=3:
                dp[i][j]=dp[i+1][j]+dp[i+1][j+1]
            else :
                dp[i][j]=dp[i+1][j]
        else :
            dp[i][j]=dp[i+1][j]
        dp[i][j]%=mod
print(dp[0][0])