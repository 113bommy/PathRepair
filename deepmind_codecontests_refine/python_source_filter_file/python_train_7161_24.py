N, T = map(int, input().split())
fs = [tuple(map(int, input().split())) for _ in range(N)]
# fs = sorted(fs)
dp = [0] * 6005

for a, b in fs:
    for t in range(T + a - 1, a - 1, -1):
        dp[t] = max(dp[t - a] + b, dp[t])
print(max(dp))
