n, A = map(int,input().split())
x = list(map(int,input().split()))

dp = [list( [0 for _ in range(10**4)] for _ in range(n+1)) for _ in range(n+1)]
dp[0][0][0] = 1


for i in range(n):
    for k in range(n):
        for s in range(sum(x)+1):
                dp[i+1][k][s] += dp[i][k][s]
                dp[i+1][k+1][s+x[i]] += dp[i][k][s]

ans = 0
for i in range(1,n+1):
    ans += dp[n][i][A*i]
print(ans)

