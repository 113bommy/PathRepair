S = int(input())
mod = 10**9+7

dp = [1]+[0]*S

for i in range(1, S+1):
    for j in range(0, i-2):
        dp[i] += dp[j]

print(dp[S]%mod)
