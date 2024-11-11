n, k = map(int, input().split())
lr = [list(map(int, input().split())) for _ in range(k)]
mod = 998244353

dp = [0] * (n + 1)
acc = [0] * (n + 1)
dp[1], acc[1] = 1, 1
for i in range(2, n + 1):
    for l, r in lr:
        dp[i] += acc[max(i - l, 0)]
        dp[i] -= acc[max(i - r, 0)]
    dp[i] %= mod
    acc[i] = (dp[i] + acc[i - 1]) % mod
print(dp[n])
