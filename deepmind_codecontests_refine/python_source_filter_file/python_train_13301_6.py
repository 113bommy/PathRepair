r, c, k = map(int, input().split())

dp = [[[0,0,0,0] for _j in range(c+1)] for _i in range(2)]
bord = [[0]*(c+1) for _i in range(r)]

for _i in range(k):
    _r, _c, _v = map(int, input().split())
    bord[_r-1][_c-1] = _v
            
for i in range(r):
    for j in range(c):
        dp[1][j][0] = max(dp[0][j])
        dp[1][j][1] = max(
            dp[1][j][0] + bord[i][j],
            dp[1][j-1][1],
            dp[1][j-1][0]+bord[i][j]
        )

        dp[1][j][2] = max(
            dp[1][j-1][2],
            dp[1][j-1][1]+bord[i][j],             
        )
        dp[1][j][3] = max(
            dp[1][j-1][3],
            dp[1][j-1][2]+bord[i][j],             
        )

        dp[0] = dp[1][::]

print(max(dp[1][c-1]))