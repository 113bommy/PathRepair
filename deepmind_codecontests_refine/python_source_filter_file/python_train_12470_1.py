import sys
readline = sys.stdin.buffer.readline

INF = 10**18+3
N, T = map(int, readline().split())

AB = [tuple(map(int, readline().split())) for _ in range(N)]
ABzero = [b for a, b in AB if a == 0]
ABnonzero = [(a, b) for a, b in AB if a]
ABnonzero.sort(key = lambda x: x[1]/x[0])


dp = [0]
for a, b in ABnonzero:
    dp2 = dp + [INF]
    for j in range(1, len(dp2)):
        dp2[j] = min(dp2[j], (dp[j-1]+1)*(a+1)+b)
    dp = [d for d in dp2 if d <= T]

ABzero.sort()
dpzero = [0] + [b+1 for b in ABzero]
for i in range(1, len(dpzero)):
    dpzero[i] += dpzero[i-1]

DP = [INF]*(N+1)
for i in range(len(dp)):
    for j in range(len(dpzero)):
        DP[i+j] = min(DP[i+j], dp[i] + dpzero[j])

DP = [d for d in DP if d <= T]
print(max(0, len(DP)-1))