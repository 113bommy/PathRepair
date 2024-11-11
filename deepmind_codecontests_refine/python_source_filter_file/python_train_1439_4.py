mod = 10 ** 9 + 7
fib = [1, 1, 2, 3, 5, 8, 13, 21, 34]

H, W, K = map(int, input().split())

dp = [0] * W
dp[0] = 1

for _ in range(H):

    T = [0] * W

    for i in range(W):
        if 0 < i:
            T[i] += T[i - 1] * fib[i - 1] * fib[W - i - 1]

        T[i] += T[i] * fib[i] * fib[W - i - 1]

        if i < W - 1:
            T[i] += dp[i + 1] * fib[i] * fib[W - i - 2]

        T[i] %= mod

    dp = T

print(dp[K - 1])