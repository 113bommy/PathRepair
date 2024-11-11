n, a = map(int, input().split())
x = [ int(i) for i in input().split() ]

dp = [ [[0] * 3000 for _ in range(55)] for __ in range(55) ]
dp[0][0][0] = 1

for j in range(n+1):
    for k in range(n+1):
        for s in range(2555):
            if j > 0 and x[j-1] > s:
                dp[j][k][s] = dp[j-1][k][s]
            elif j > 0 and k >= 1 and s >= x[j-1]:
                dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]]

ans = 0

for k in range(1, n+1):
    ans += dp[n][k][k*a]

print(ans)
