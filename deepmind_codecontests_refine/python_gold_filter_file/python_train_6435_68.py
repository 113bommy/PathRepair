mod = 10 ** 9 + 7

K = map(int, list(input()))
D = int(input())

s = 0
dp = [0] * D
for k in K:
    T = [0] * D
    for i, dpi in enumerate(dp):
        for x in range(10):
            T[(i + x) % D] = (T[(i + x) % D] + dpi) % mod
    for x in range(k):
        T[(s + x) % D] += 1

    s = (s + k) % D
    dp = T

print((dp[0] + (-1 if s != 0 else 0)) % mod)