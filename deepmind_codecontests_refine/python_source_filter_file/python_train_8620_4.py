n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
mod = 10 ** 9 + 7

dp = [0] * (1 << n)
dp[0] = 1

bitcount = [0]
for _ in range(n):
    bitcount += [i+1 for i in bitcount]

# 配るDP
for bit in range((1 << n) - 1):
    i = bitcount(bit)
    for j in range(n):
        if a[i][j] and ((bit >> j) & 1 ^ 1):
            newbit = bit | (1 << j)
            dp[newbit] += dp[bit]
            dp[newbit] %= mod
print(dp[(1 << n) - 1])
