N=int(input())
s=input()
l=len(s)
dp=[[0]*(N+2) for i in range(N)]
dp[0][1]=2
dp[0][0]=1
mod=10**9+7
for i in range(N-1):
    for j in range(i+2):
        if j==0:
            dp[i+1][j+1]+=2*dp[i][j]
            dp[i+1][j+1]%=mod
            dp[i+1][j]+=dp[i][j]
            dp[i+1][j]%=mod            
            continue
        dp[i+1][j+1]+=2*dp[i][j]
        dp[i+1][j+1]%=mod
        dp[i+1][j-1]+=dp[i][j]
        dp[i+1][j-1]%=mod  
t=pow(2,(mod-2),mod)
t=pow(t,l,mod)
print((dp[-1][l]*t)%mod)