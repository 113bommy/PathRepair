def main():
    A, B, C, D = map(int, input().split())
    mod = 998244353

    dp = [[0]*(D+2) for i in range(C+2)]
    dp[A][B] = 1
    for i in range(A, C+1):
        for j in range(B, D+1):
            ret = dp[i][j]
            if i-A == j-B == 1:
                ret -= (i-1)*(j-1)
            else:
                ret -= dp[i-1][j-1]*(j-1)*(i-1)
            ret %= mod
            dp[i][j] = ret
            dp[i+1][j] += ret * j
            dp[i][j+1] += ret * i

    print(dp[-2][-2])


main()
