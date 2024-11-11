mod = 998244353

A, B, C, D = map(int, input().split())

dp = [0] * B + [pow(A, i, mod) for i in range(D + 1 - B)]
for a in range(A + 1, C + 1):
    T = [0] * (D + 1)
    for b in range(B, D + 1):
        T[b] = (a * T[b - 1] + b * dp[b] - (a - 1) * (b - 1) * dp[b - 1]) % mod
    dp = T

print(dp[D])