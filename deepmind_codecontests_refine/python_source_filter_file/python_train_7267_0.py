def main():
    N = int(input())
    A = list(map(int, input().split()))
    a = A.count(1)
    b = A.count(2)
    c = A.count(3)
    floatN = N*1.0
    dp = [[[0]*(N+1) for i in range(N+1)] for j in range(N+1)]

    for k in range(c+1):
        for j in range(b+c + 1 - k):
            for i in range(N + 1 - k - j):
                if i + j+k == 0:
                    continue
                dp[i][j][k] = floatN
                if i > 0:
                    dp[i][j][k] += dp[i-1][j][k] * i
                if j > 0:
                    dp[i][j][k] += dp[i+1][j-1][k] * j
                if k > 0:
                    dp[i][j][k] += dp[i][j+1][k-1] * k
                dp[i][j][k] /= (i+j+k)
    print(dp[a][b][c])


main()
