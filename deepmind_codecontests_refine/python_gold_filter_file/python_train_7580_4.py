from itertools import accumulate

N = int(input())
balls = []

# 初期位置を覚えておく
placeB = [0] * N
placeW = [0] * N

# 入力処理 & 初期位置処理
for i in range(2*N):
    c, a = input().split()
    a = int(a)
    balls.append([c, a])
    if c == "B":
        placeB[a-1] = i
    else:
        placeW[a-1] = i


costB = [[0]*(2*N+1) for i in range(N+1)]  # i番目まででjより大きいB
costW = [[0]*(2*N+1) for i in range(N+1)]  # i番目まででjより大きいW

for i in range(N):
    for j in range(2*N):
        if balls[j][1] > i:
            if balls[j][0] == "B":
                costB[i][j+1] = 1
            else:
                costW[i][j+1] = 1

# 累積和
costB = [list(accumulate(cB)) for cB in costB]
costW = [list(accumulate(cW)) for cW in costW]

# dp
dp = [[float('inf')]*(N+1) for i in range(N+1)]
dp[0][0] = 0
for b in range(N+1):
    for w in range(N+1):
        if b > 0:
            dp[b][w] = min(dp[b][w], dp[b-1][w] + costB[b][placeB[b-1]] + costW[w][placeB[b-1]])
        if w > 0:
            dp[b][w] = min(dp[b][w], dp[b][w-1] + costW[w][placeW[w-1]] + costB[b][placeW[w-1]])

print(dp[N][N])
