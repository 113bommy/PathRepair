s=int(input())
dp=[0 for i in range(s+10)]
dp[3]=1
mod=10**9+7
for i in range(3,s+3):
    dp[i]=1
    for j in range(i-2): dp[i]=(dp[i]+dp[j])%mod
print(dp)