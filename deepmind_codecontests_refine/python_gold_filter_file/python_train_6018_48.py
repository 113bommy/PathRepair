S = input()
mod = 10 ** 9 + 7
dp = [0] * 13
dp[0] = 1
for s in S:
    d = [0] * 13
    if s == '?':
        for i in range(13):
            for j in range(10):
                d[(10*i + j) % 13] += dp[i]
    else:
        for i in range(13):
            d[(10*i + int(s)) % 13] += dp[i]
    dp = [x % mod for x in d]
print(d[5] % mod)
