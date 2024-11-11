# 入力
N = int(input())
p = [float(x) for x in input().split()]

# DPテーブルを初期化
dp = [[0 for x in range(N+1)] for n in range(N+1)]
dp[0][0] = 1

# ループを回す
for i in range(N):
    for x in range(N):
        dp[i+1][x+1] += dp[i][x]*p[i]
        dp[i+1][x] += dp[i][x]*(1-p[i])

# 答えを得て出力
print(sum(dp[N][N//2+1:]))
