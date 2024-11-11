import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, K = mapint()
dp = [0]*(N*2+1)
dp[1] = 1
dp[2] = -1
mod = 998244353
LR = [list(mapint()) for _ in range(K)]
for i in range(1, N+1):
    dp[i] = (dp[i]+dp[i-1])%mod
    for l, r in LR:
        dp[i+l] = (dp[i+l]+dp[i])%mod
        dp[i+r+1] = (dp[i+r+1]-dp[i])%mod

print(dp[N])
    