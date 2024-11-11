n, k = map(int, input().split())
h = list(map(int, input().split()))

dp = [0] * n

for i in range(1, n):
    s = max(i-k, 0)
    dp[i] = min(dp[j] + abs(h[i]-h[j]) for j in range(s, i))

print(dp[-1])