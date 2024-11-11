def main():
    mod = 998244353
    a, b, c, d = map(int, input().split())
    dp = [[0]*(d+1) for _ in [0]*(c+1)]
    dp[a][b] = 1
    for i in range(a+b+1, c+d+1):
        for p in range(c, a-1, -1):
            q = i-p
            if q > d:
                break
            if q < 0:
                continue
            dp[p][q] = (q*dp[p-1][q]+p*dp[p][q-1] -
                        (p-1)*(q-1)*dp[p-1][q-1]) % mod
    print(dp[c][d])


main()
