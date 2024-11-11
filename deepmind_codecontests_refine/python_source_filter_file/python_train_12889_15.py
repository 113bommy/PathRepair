N, W = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]
dp = [10**9+7] * (10**3+2)
dp[0] = 0

for i in range(1, N+1):
    w, v = wv[i-1]
    for j in range(10**3, 0, -1):
        if j-v >= 0:
            dp[j] = min(dp[j], dp[j-v]+w)

ret = 0
for i in range(1, 10**3+1):
    if dp[i] <= W:
        ret = i
print(ret)

