n,m=map(int,input().split())
a=[int(input()) for _ in range(m)]
dp=[1]+[0 for _ in range(n)]
mod=1000000007
for i in range(1,n+1):
    if i in a:
        dp[i]=0
    else:
        dp[i]=(dp[i-1]+dp[i-2])%mod
print(dp[-1])