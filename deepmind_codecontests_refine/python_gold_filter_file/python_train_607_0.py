H,W = map(int,input().split())
src = [list(map(int,input().split())) for i in range(H)]

dp = [[[0 for ex in range(W)] for sx in range(W)] for xy in range(H+W-1)]
dp[0][0][0] = src[0][0]
for xy in range(H+W-2):
    n = min(xy+1,H,W,H+W-xy-1)
    sx0 = max(0,xy-H+1)
    for sx in range(sx0, sx0+n):
        for ex in range(sx, sx0+n):
            sy,ey = xy-sx, xy-ex
            if sx < W-1 and ex < W-1:
                gain = src[sy][sx+1]
                if sx+1 != ex+1: gain += src[ey][ex+1]
                if dp[xy+1][sx+1][ex+1] < dp[xy][sx][ex] + gain:
                    dp[xy+1][sx+1][ex+1] = dp[xy][sx][ex] + gain
            if sx < W-1 and ey < H-1:
                gain = src[sy][sx+1]
                if sx+1 != ex: gain += src[ey+1][ex]
                if dp[xy+1][sx+1][ex] < dp[xy][sx][ex] + gain:
                    dp[xy+1][sx+1][ex] = dp[xy][sx][ex] + gain
            if sy < H-1 and ex < W-1:
                gain = src[sy+1][sx]
                if sx != ex+1: gain += src[ey][ex+1]
                if dp[xy+1][sx][ex+1] < dp[xy][sx][ex] + gain:
                    dp[xy+1][sx][ex+1] = dp[xy][sx][ex] + gain
            if sy < H-1 and ey < H-1:
                gain = src[sy+1][sx]
                if sx != ex: gain += src[ey+1][ex]
                if dp[xy+1][sx][ex] < dp[xy][sx][ex] + gain:
                    dp[xy+1][sx][ex] = dp[xy][sx][ex] + gain

print(dp[-1][-1][-1])