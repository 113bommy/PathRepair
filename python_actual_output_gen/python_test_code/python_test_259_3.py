import itertools
n, m, k = map(int, input().split())
A = list(map(int, input().split()))
acc = [0] + list(itertools.accumulate(A))
rsum = lambda i, j: acc[j + 1] - acc[i]
dp = [0] * n
ans = 0
for i, a in enumerate(A):
    if i >= m:
        dp[i] = max(dp[i], dp[i - m] + rsum(i - m + 1, i) - k)
    for j in range(i, max(-1, i - m + 1), -1):
        dp[i] = max(dp[i], rsum(j, i) - k)
    ans = max(ans, dp[i])
print(ans)