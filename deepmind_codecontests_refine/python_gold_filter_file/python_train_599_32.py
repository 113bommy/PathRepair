import sys

input = sys.stdin.buffer.readline
n, s = map(int, input().split())
A = list(map(int, input().split()))
dp = [[0] * (s + 1) for _ in range(n + 1)]

mod = 998244353
# dp[i][s] A[i]まで見た時、合計sになる数。
# 各々の地点で新しく開始されるものも有るので毎回dp[i][0]は＋1
dp[0][0] = 1
ans = 0
for i in range(n):
    ni = i + 1
    for j in range(s + 1):
        nj = j
        dp[ni][nj] += dp[i][j]
        dp[ni][nj] %= mod
        nj = j + A[i]
        if nj <= s:
            dp[ni][nj] += dp[i][j]
            dp[ni][nj] %= mod
    dp[ni][0] += 1
    ans += dp[ni][s]
    ans %= mod
print(ans)
