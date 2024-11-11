n,a,b,k=map(int,input().split())
dp=[[0 for i in range(n+1)] for j in range(2)]
dp[0][a]=1
now=1
last=0
mod=1000000007
for i in range(k):
    for j in range(1,n+1):
        d=max(abs(j-b)-1,0)
        if j!=n:
            dp[now][j+1]=(dp[last][j]+dp[now][j+1])%mod
            dp[now][min(j+d+1,n)]=(dp[now][min(j+d+1,n)]-dp[last][j])%mod
        if j!=1:
            dp[now][j]=(dp[now][j]-dp[last][j])%mod
            dp[now][max(j-d,1)]=(dp[now][max(j-d,1)]+dp[last][j])%mod
    for i1 in range(1,n+1):
        dp[now][i1]=(dp[now][i1]+dp[now][i1-1])%mod
        dp[last][i1]=0
    aux=now
    now=last
    last=aux
print(sum(dp[last])%mod)
