def main():
    n = int(input())
    c = []
    mod = 10 ** 9 + 7
    state = [0 for i in range(n+10000)]
    dp = [0 for i in range(n+1)]
    dp[0] = 1
    for i in range(n):
        c_i = int(input())

        if state[c_i] >= 1 and state[c_i] != i:
            dp[i+1] = (dp[state[c_i]] + dp[i]) % mod
        else:
            dp[i+1] = dp[i] % mod

        state[c_i] = i + 1
    print(dp[-1] % mod)

main()