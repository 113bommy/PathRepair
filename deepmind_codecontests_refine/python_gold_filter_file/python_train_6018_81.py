s=input()
l=len(s)
dp=[[0]*13 for i in range(l+1)]
dp[0][0]=1
for i in range(1,l+1):
    if s[i-1]=='?':
        for k in range(13):
           for j in range(10):
                dp[i][(k*10+j)%13]+=dp[i-1][k]
                dp[i][(k*10+j)%13]%=10**9+7
    else:
        idx=int(s[i-1])
        for j in range(13):
            dp[i][(j*10+idx)%13]=dp[i-1][j]
print(dp[-1][5]%(10**9+7))