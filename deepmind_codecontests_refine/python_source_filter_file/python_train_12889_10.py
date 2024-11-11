N, W = map(int, input().split())
V = 10**5
INF = 10**18
dp = [INF]*(V+1)

dp[0] = 0
for i in range(N):
    w, v = map(int, input().split())
    for j in range(V-1, v-1, -1):
        if dp[j-v] + w <= W:
            dp[j] = min(dp[j], dp[j-v] + w)
for i in range(V-1, -1, -1):
    if dp[i] < INF:
        print(i)
        break