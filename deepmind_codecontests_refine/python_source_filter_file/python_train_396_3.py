import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

S = read().rstrip()

from collections import defaultdict

INF = 10**9
dp = defaultdict(lambda:INF)
dp[0] = 0

cum = 0
for x in S:
    cum ^= 1<<(x-97)
    x = min(dp[cum^(1<<i)] for i in range(26)) + 1
    if dp[cum] > x:
        dp[cum] = x

answer = max(1,dp[cum])
print(answer)