n, MOD = map(int, input().split())

n3 = n * 3
dp = [[0] * int(i * 1.5 + 5) for i in range(n3 + 1)]
dp[0][0] = dp[1][1] = dp[2][2] = dp[2][-1] = 1

for i in range(3, n3 + 1):
    i12 = (i - 1) * (i - 2)
    dpi3, dpi2, dpi1, dpi = dp[i - 3:i + 1]
    for j in range(-(i // 2), i + 1):
        tmp = dpi3[j] * i12
        tmp += dpi2[j + 1] * (i - 1)
        tmp += dpi1[j - 1]
        dpi[j] = tmp % MOD

print(sum(dp[-1][:n3 + 1]) % MOD)
