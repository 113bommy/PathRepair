N = int(input())
A = [0] + list(map(int, input().split()))

INF = 10 ** 12

dp = [[0] * (N) for _ in range(N)]

for i in range(N):
    A[i + 1] += A[i]

for j in range(1, N):
    for i in range(N - j):
        tmp = INF
        for k in range(i, i + j):
            # print (i, i + j, k + 1)
            tmp = min(tmp, dp[i][k] + dp[k + 1][i + j])
        dp[i][i + j] = tmp + A[i + j + 1] - A[i]

print (dp[0][N - 1])
