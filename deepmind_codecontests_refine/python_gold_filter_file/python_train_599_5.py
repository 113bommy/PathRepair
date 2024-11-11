def main():
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    mod = 998244353

    dp = [[0]*3001 for _ in [0]*n]
    dp[0][a[0]] = 1
    for j, i in enumerate(a[1:]):
        dp[j+1][i] += (j+2)
        for k in range(3001-i):
            dp[j+1][i+k] = (dp[j+1][i+k]+dp[j][k]) % mod
        for k in range(3001):
            dp[j+1][k] = (dp[j+1][k]+dp[j][k]) % mod
    print(sum([dp[i][s] for i in range(n)]) % mod)


main()