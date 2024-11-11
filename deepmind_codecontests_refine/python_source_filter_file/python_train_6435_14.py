mod = 10**9+7
k = input()
d = int(input())

l = len(k)

dp = [[0 for _ in range(d)] for _ in range(l+1)]
dp2 = [[0 for _ in range(d)] for _ in range(l+1)]

dp[0][0] = 1
dp2[0][0] = 1

for i in range(1, l+1):
    if i == 1:
        for p in range(10):
            if p > int(k[i-1]):
                continue
            for j in range(d):
                if p < int(k[i-1]):
                    dp[i][(j+p) % d] += dp[i-1][j]
                    dp[i][(j+p) % d] %= mod
                elif p == int(k[i-1]):
                    dp2[i][(j+p) % d] += dp2[i-1][j]
                    dp2[i][(j+p) % d] %= mod
        continue

    for p in range(10):
        for j in range(d):
            dp[i][(j+p) % d] += dp[i-1][j]
            dp[i][(j+p) % d] %= mod

        if p > int(k[i-1]):
            continue

        for j in range(d):
            if p < int(k[i-1]):
                dp[i][(j+p) % d] += dp2[i-1][j]
                dp[i][(j+p) % d] %= mod
            elif p == int(k[i-1]):
                dp2[i][(j+p) % d] += dp2[i-1][j]
                dp2[i][(j+p) % d] %= mod

print(dp[l][0]+dp2[l][0]-1)
