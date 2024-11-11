N, W = map(int, input().split())
dp = [0] + [W+1] * (N*100)
for i in range(N):
    x, y = map(int, input().split())
    for j in range(i*100, -1, -1):
        if dp[j+y] > dp[j] + x:
            dp[j+y] = dp[j] + x

for v, w in zip(range(N*100, -1, -1), dp[::-1]):
    if w < W+1:
        print(v)
        break
