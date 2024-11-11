def main():
    r, c, k = map(int, input().split())
    d = [[0]*c for _ in [0]*r]
    for _ in range(k):
        t1, t2, t3 = map(int, input().split())
        d[t1-1][t2-1] = t3
    dp = [[0]*4 for _ in [0]*c]
    dp[0][1] = d[0][0]
    for x in range(r):
        dp2 = [[0]*4 for _ in [0]*c]
        for y in range(c):
            for z in range(4):
                if y != c-1:
                    if z != 3:
                        dp[y+1][z+1] = max(dp[y+1]
                                           [z+1], dp[y][z]+d[x][y+1])
                    dp[y+1][z] = max(dp[y+1][z], dp[y][z])
            if x != r-1:
                dp2[y][1] = max(dp2[y][1],
                                max(dp[y])+d[x+1][y])
                dp2[y][0] = max(dp2[y][0], max(dp[y]))
        if x != r-1:
            dp = dp2
    print(max(dp[c-1]))


main()
