import sys
N, M = map(int, input().split())
sys.setrecursionlimit(10**5)
E = [[] for _ in range(N)]
for i in range(M):
    x, y = map(int, input().split())
    E[x-1].append(y-1)

dp = [-1]*N


def rec(v):
    if dp[v] != -1:
        return dp[v]
    if len(E[v]) == 0:
        dp[v] = 0
        return dp[v]

    for to in E[v]:
        dp[v] = max(dp[v], rec(to)+1)
    return dp[v]


for i in range(N):
    dp[i] = rec(i)
print(max(dp))