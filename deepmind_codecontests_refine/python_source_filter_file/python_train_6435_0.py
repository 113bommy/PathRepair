mod = 10 ** 9 + 7

K = map(int, iter(input()))
D = int(input())

s = 0
dp = [0] * D
for k in K:
    ndp = [0] * D
    for d in range(10):
        for i, dpi in enumerate(dp):
            ndp[(i + d) % D] += dpi

    for d in range(k):
        ndp[(s + d) % D] += 1

    s = (s + k) % D
    dp = [x % mod for x in ndp]

print((dp[0] - (s != 0)) % mod)