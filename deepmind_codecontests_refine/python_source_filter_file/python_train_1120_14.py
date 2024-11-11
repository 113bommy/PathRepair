import sys
input = sys.stdin.readline

mod = 998244353

n, k = map(int, input().split())
lr = [list(map(int, input().split())) for _ in range(k)]

dp = [0] * (n+1)
dp[1] = 1

for i in range(1, n):
    dp[i+1] += dp[i]
    for l, r in lr:
        dp[i+1] += dp[max(i-l+1, 0)] - dp[max(i-r, 0)]
        dp[i+1] %= mod

print(dp[n]-dp[n-1])