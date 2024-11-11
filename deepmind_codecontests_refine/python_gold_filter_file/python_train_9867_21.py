def main():
    A, B, C, D = map(int, input().split())

    c = C - A
    d = D - B
    mod = 998244353
    dp = [[0]*(d+1) for i in range(c+1)]
    dp[0][0] = 1

    for i in range(c+1):

        for j in range(d+1):
            ret = 0
            if i == 0 and j == 0:
                continue
            if i > 0 and j > 0:
                if i == j == 1:
                    ret -= (A+i-1) * (B+j-1)
                else:
                    ret -= dp[i-1][j-1]
                    ret *= (A+i-1)*(B+j-1)
            ret += dp[i-1][j]*(B+j) + dp[i][j-1]*(A+i)

            ret %= mod
            dp[i][j] = ret
    print(dp[c][d])


main()

