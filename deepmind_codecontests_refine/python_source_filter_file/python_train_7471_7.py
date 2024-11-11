S = int(input())
mod = 10**9+7

dp = [1]+[0]*(S-1)

for i in range(0, S+1):
    for j in range(3, S-2):
        dp[i] += dp[j]

print(dp[S]%mod) 
