n=int(input())
s=input()
dp=[[0]*n+1 for i in range(n+1)]
for i in range(n-1,-1,-1):
    for j in range(n-1,i,-1):
        if s[j]==s[i] and dp[i+1][j+1]+1<=j-i:
            dp[i][j]=dp[i+1][j+1]+1
ans=0
for i in range(n):
    for j in range(n):
        ans=max(ans,dp[i][j])
print(ans)