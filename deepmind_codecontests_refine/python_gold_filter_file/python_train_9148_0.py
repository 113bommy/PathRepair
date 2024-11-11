def main():
    MOD = 1000000007
    s,t = input(),input()
    n,m = len(s),len(t)
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    dp[0][0] = 1
    for i in range(n):
        for j in range(m-1,-1,-1):
            dp[i+1][j] += dp[i][j]
            dp[i+1][j] %= MOD
            if s[i] == t[j]:
                dp[i+1][j+1] += dp[i][j]
                dp[i+1][j+1] %= MOD
    sum = 0
    for i in range(n+1):
        sum += dp[i][m]
    print(sum%MOD)

if __name__ == "__main__":
    main()