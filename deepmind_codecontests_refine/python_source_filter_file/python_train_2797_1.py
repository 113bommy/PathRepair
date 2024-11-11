from sys import stdin

case = 0
while(True):
    case += 1
    W = int(stdin.readline())
    if not W: break
    print("Case %d"%case)
    N = int(stdin.readline())
    v = [0] * N
    w = [0] * N
    dp = [[0]*(W + 1) for _ in range(N + 1)]

    for k in range(N):
        v[k], w[k] = map(int, stdin.readline().split(","))
    for i in range(N-1,-1,-1):
        for j in range(W+1):
            if j < w[i]:
                dp[i][j] = dp[i + 1][j]
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i])
    print(dp[0][W])
    for i in range(W+1):
        if dp[0][i] == dp[0][W]: print(i); break


