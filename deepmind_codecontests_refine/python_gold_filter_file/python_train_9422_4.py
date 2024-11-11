n = int(input())
p = list(map(int, input().split()))

dp = [1]
d = {i : 0 for i in range(1, n + 1)}
d[p[0]] = 1
for i in range(1, n):
    if p[i] == 1:
        dp.append(dp[i - 1])
        d[p[i]] = 1
    elif d[p[i] - 1] == 0:
        dp.append(dp[i - 1])
        d[p[i]] = 1
    elif d[p[i] - 1] + 1 > dp[i - 1]:
        dp.append(d[p[i] - 1] + 1)
        d[p[i]] = d[p[i] - 1] + 1
    else:
        dp.append(dp[i - 1])
        d[p[i]] = d[p[i] - 1] + 1

print(n - dp[n - 1])
