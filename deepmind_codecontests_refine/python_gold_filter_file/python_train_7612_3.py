from itertools import *

MOD = int(1e9 + 7)
n, l, r = tuple(map(int, input().split()))

c = list(repeat(r//3 - l//3, 3))
for i in range(r % 3, -1, -1): c[i] += 1
for i in range(0, l % 3, 1): c[i] -= 1

dp = [[0 for _ in range(3)] for _ in range(n+1)]
dp[1] = c
for i in range(2, n+1):
    dpl = dp[i-1]
    for j, k in product(range(3), repeat=2):
        dp[i][j] = (dp[i][j] + dpl[k]*c[(j+3-k)%3]) % MOD
print(dp[n][0])
