import sys
input = sys.stdin.readline

n = int(input())
a = [int(x) for x in input().split()]

dp = [[0]*(n + 1) for _ in range(n + 1)]

for i in range(n + 1):
    dp[i][i] = 0

for width in range(1, n + 1):
    for l in range(n + 1):
        r = width + l
        if r <= l or r > n:
            continue
        if (r - l) % 2 == 1:
            dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1])
        else:
            dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1])

print(dp[0][n])


