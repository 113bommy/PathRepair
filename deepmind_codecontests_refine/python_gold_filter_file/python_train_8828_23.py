import sys
sys.setrecursionlimit(10 ** 6)

n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for i in range(m):
    f, t = map(int, input().split())
    graph[t].append(f)

dp = [None] * (n + 1)
def dfs(now):
    if dp[now] is not None:
        return dp[now]

    if not graph[now]:
        return 0

    r = max(dfs(parent) for parent in graph[now]) + 1
    dp[now] = r
    return r

print(max(dfs(i) for i in range(1, n + 1)))
