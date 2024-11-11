n, W = map(int, input().split())
ab = [tuple(map(int, input().split()))for _ in range(n)]
ab.sort(reverse=True)

dp = [0]*W
for w, v in ab:
    for j in reversed(range(W)):
        if j-w < 0:
            break
        if dp[j] < dp[j-w]+v:
            dp[j] = dp[j-w]+v
    if dp[0] < v:
        dp[0] = v
print(max(dp))
