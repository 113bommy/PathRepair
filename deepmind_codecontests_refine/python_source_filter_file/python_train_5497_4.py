n, k = map(int, input().split())
MOD = 10 ** 9 + 7


dist = [(n + 1, n + 1)]
r = n + 1
for i in range(2, n + 10):
    # [l, r)
    r = dist[-1][0]
    l = n // i + 1
    if r - l <= 1:
        break
    dist.append((l, r))

while True:
    if r == 1:
        break
    dist.append((r - 1, r))
    r -= 1

dist = dist[::-1]
del dist[-1]


length = [r - l for l, r in dist]
dp = [[0] * len(dist) for i in range(k)]
for i in range(len(dist)):
    dp[0][i] = length[i]


for i in range(k - 1):
    ru = 0
    for j in range(len(dist)):
        ru += dp[i][j]
        ru %= MOD
        dp[i + 1][~j] += ru * length[~j]
        dp[i + 1][~j] %= MOD

print(sum(dp[-1]) % MOD)