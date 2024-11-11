H, W, K = map(int, input().split())
mod = 1000000007

draw_line = [0 for _ in range(W)]
draw_line[0] = 1
if W > 1:
    draw_line[1] = 1
for i in range(2, W):
    draw_line[i] = draw_line[i-1] + draw_line[i-1]

dp = [[0 for _ in range(W)] for _ in range(H+1)]
dp[0][0] = 1
for h in range(1, H+1):
    for w in range(W):
        # from left
        if w > 0:
            dp[h][w] += dp[h-1][w-1] * draw_line[w-1] * draw_line[W-w-1]
        # from up
        dp[h][w] += dp[h-1][w] * draw_line[w] * draw_line[W-w-1]
        # from right
        if w < W-1:
            dp[h][w] += dp[h-1][w+1] * draw_line[w] * draw_line[W-w-2]

print(dp[H][K-1]%mod)
