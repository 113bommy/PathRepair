S=list(input())
MOD=10**9+7
dp=[[0]*13 for i in range(len(S)+1)]
dp[0][0]=1
for i in range(len(S)):
    if S[i]=="?":
        for j in range(10):
            for k in range(13):
                dp[i+1][(10*k+j)%13]+=dp[i][k]%MOD
    else:
        a=int(S[i])
        for k in range(13):
            dp[i+1][(10*k+a)%13]+=dp[i][k]%MOD
print(dp[len(S)][5]%MOD)