n=int(input())
mod=10**9+7
if n>=2:
    dp=[0 for i in range(n)]
    dp[0],dp[1]=1,2
    ans=0
    for i in range(2,n):
        dp[i]=(dp[i-1]+dp[i-2])%mod 
        ans=(ans+dp[i])%mod 
    print(ans)
else:
    print(1)