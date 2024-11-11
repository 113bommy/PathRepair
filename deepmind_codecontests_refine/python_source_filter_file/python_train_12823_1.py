for _ in range(int(input())):
    N, M = map(int, input().split())
    X = [[int(a) for a in input().split()] for _ in range(N)]
    Y = [[X[i][j] for i in range(N)] for j in range(M)]
    ma = 0
    dp = [[0] * (1<<N) for _ in range(M+1)]
    for j in range(M):
        for mask in range(1<<N):
            maskpre = mask - 1
            while maskpre >= 0:
                maskpre &= mask
                ma = 0
                for k in range(N):
                    s = 0
                    for i in range(N):
                        if (maskpre >> i) & 1 == 0 and (mask >> i) & 1:
                            s += X[i-k][j]
                    ma = max(ma, s)
                dp[j+1][mask] = max(dp[j+1][mask], dp[j][maskpre] + ma)
                
                maskpre -= 1
    print(dp[-1][-1])
