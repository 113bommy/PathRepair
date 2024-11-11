N, W = map(int, input().split())

MAX_V = 10 ** 3
wv = [list(map(int, input().split())) for _ in range(N)]

dp = [10**9+7 for _ in range(MAX_V + 1)]
dp[0] = 0

for w, v in wv:
    for j in range(MAX_V, -1, -1):
        if j - v >= 0:
            dp[j] = min(dp[j],dp[j - v] + w)

mv = 0
for i in range(MAX_V + 1):
    if dp[i] <= W:
        mv = i

print(mv)
