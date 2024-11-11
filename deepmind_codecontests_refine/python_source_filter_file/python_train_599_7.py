def main():
    N, S = map(int, input().split())
    A = list(map(int, input().split()))
    mod = 998244353
    ans = 0
    dp = [0]*S

    for i, a in enumerate(A):
        if a > S:
            continue
        dp[0] += 1
        ans += dp[S-a]*(N-i)

        for j, x in enumerate(dp[:S-a]):
            dp[j+a] += x
    print(ans % mod)


main()
