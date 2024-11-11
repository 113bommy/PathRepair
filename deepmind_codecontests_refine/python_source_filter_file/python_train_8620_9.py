MOD = 1e9 + 7

n = int(input())
can = []
for _ in range(n):
    can.append([int(c) for c in input().split()])

dp = [0] * (2 ** n)
dp[0] = 1

for mask in range(2 ** n - 1):
    a = bin(mask).count('1')
    for b in range(n):
        if can[a][b] and not(mask & (1 << b)):
            m2 = mask ^ (1 << b)
            dp[m2] = dp[m2] + dp[mask]
            if dp[m2] > MOD:
                dp[m2] -= MOD


print(dp[(2**n) - 1])
