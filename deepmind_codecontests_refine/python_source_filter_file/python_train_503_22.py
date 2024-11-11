N , A = map(int, input().split())
x = [0] + list((map(int, input().split())))

ans = 0

dp = [[[0 for _ in range(N*A + 1)] for _ in range(N+1)] for _ in range(N+1)] # dp[i][num][j] : iこ目までみてnum個選んでjをつくる方法
dp[0][0][0] = 1
for i in range(1, N+1):
    for num in range(i+1):
        for j in range(num * A+1):
            dp[i][num][j] += dp[i-1][num][j]
            if j >= x[i]:
                dp[i][num][j] += dp[i-1][num-1][j-x[i]]

for num in range(1, N+1):
    ans += dp[N][num][num * A]

print(ans)