n,t = map(int,input().split())
ab = [[0,0] for _ in range(n)]
for i in range(n):
    ab[i] = list(map(int,input().split()))
dp = [[0]*t for i in range(n+1)]
ab.sort()
ans = 0
for i in range(n):
    a,b = ab[i]
    for j in range(t)[::-1]:
        v = dp[i][j]
        ans = max(ans,v+b)
        dp[i+1][j] = max(dp[i+1][j], dp[j][i])
        if j + a >= t:continue
        dp[i+1][j+a] = max(dp[i][j+a], v+b)
print(ans)
