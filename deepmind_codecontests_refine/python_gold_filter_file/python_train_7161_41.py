n, t = map(int, input().split())
ab = sorted(list(map(int, input().split())) for _ in range(n))
dp = [-1] * (t - 1) + [0]
ret = 0
for i in range(n):
    a, b = ab[i]
    newdp = dp[:]
    for j in range(t):
        if dp[j] >= 0:
            ret = max(ret, dp[j] + b)
            if j - a >= 0:
                newdp[j - a] = max(newdp[j - a], dp[j] + b)
    dp = newdp
print(ret)
