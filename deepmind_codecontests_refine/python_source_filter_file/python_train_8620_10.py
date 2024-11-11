n = int(input())
a = [list(map(int, input().split())) for i in range(n)]
mod = 10 ** 9 + 7
dp = [0] * (1 << n)
dp[0] = 1
for i in range(1, 1 << n):
    k = bin(i).count("1")
    for j in range(n):
        if i >> j & 1 and a[k - 1][j]:
            dp[i] += dp[i ^ (1 << j)]
    dp[i] %= mod
print(dp[(1 << n)-1])
