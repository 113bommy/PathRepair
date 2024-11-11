from collections import Counter

n = int(input())
cnt = Counter(input().split())
c1, c2, c3 = cnt['1'], cnt['2'], cnt['3']
total = c1 + 2 * c2 + 3 * c3
c23 = c2 + c3
dp = [[[0.0] * (c3 + 1) for _ in range(c2 + c3 + 1)] for _ in range(n + 2)]

for k in range(1, n + 1):
    still = n / k
    for a1 in range(k, max(-1, 2 * k - total - 1, k - c23 - 1), -1):
        dpap, dpac, dpan = dp[a1 - 1], dp[a1], dp[a1 + 1]
        for a2 in range(min(k - a1, c2 + c3), max(-1, 3 * k - 2 * a1 - total - 1, k - a1 - c3 - 1), -1):
            a3 = k - a1 - a2
            tmp = 0
            if a1:
                tmp += dpap[a2][a3] * a1
            if a2:
                tmp += dpan[a2 - 1][a3] * a2
            if a3:
                tmp += dpac[a2 + 1][a3 - 1] * a3
            dpac[a2][a3] = tmp / k + still
print(dp[c1][c2][c3])
