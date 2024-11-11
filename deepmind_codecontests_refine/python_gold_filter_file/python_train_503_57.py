n,a=[int(_) for _ in input().split()]
x=[int(_) for _ in input().split()]
dp=[[[0 for k in range(2551)] for j in range(51)] for i in range(n)]
dp[0][1][x[0]]=1;dp[0][0][0]=1
for i in range(n-1):
    for j in range(50):
        for k in range(2501):
            dp[i+1][j+1][k+x[i+1]] += dp[i][j][k]
            dp[i+1][j][k] += dp[i][j][k]
ans=0
for j in range(1,n+1):ans += dp[-1][j][j*a]
print(ans)