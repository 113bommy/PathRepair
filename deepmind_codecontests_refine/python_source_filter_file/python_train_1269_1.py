MOD = 1000000007
n, m = list(map(int, input().split()))
mx = max(n, m)
dp = [0] * mx
dp[0] = 2
if mx >= 2:
    dp[1] = 4

for i in range(2, mx):
    dp[i] = (dp[i-1] + dp[i-2]) % MOD

ans = dp[n-1] + dp[m-1] - 2
print(int(ans))
