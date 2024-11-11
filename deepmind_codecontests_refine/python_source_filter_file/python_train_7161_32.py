N, T = map(int, input().split())
p = []
for i in range(N):
    A, B = map(int, input().split())
    p.append([A, B])
sorted(p)

dp = [[0]*3005 for _ in range(3005)]
ans = 0
for i in range(N):
    for j in range(T):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        nextj = j + p[i][0]
        if nextj < T:
            dp[i+1][nextj] = max(dp[i+1][nextj], dp[i][j] + p[i][1])
    now = dp[i][T-1] + p[i][1]
    ans = max(ans, now)

print(ans)
