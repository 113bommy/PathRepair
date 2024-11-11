def main():
    MOD = 998244353

    A, B, H, W = map(int, input().split())

    dp = [[0] * (W + 1) for _ in range(H + 1)]
    dp[A][B] = 1

    for h in range(A, H + 1):
        for w in range(B, W + 1):
            if h == A and w == B: continue
            t = 0
            if h > A:
                t += dp[h - 1][w] * w
            if w > B:
                t += dp[h][w - 1] * h
            if h > A and w > B:
                t -= dp[h - 1][w - 1] * (h - 1) * (w - 1)
            dp[h][w] = t % MOD

    print(dp[H][W])


if __name__ == '__main__':
    main()
