N, T = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]

AB.sort(reverse=True)
dp = [0] * (T + 1)

for a, b in AB:
    for t in range(T):
        x = dp[t+a]+b if t+a < T else b
        dp[t] = max(dp[t], x)

ans = dp[0]
print(ans)
