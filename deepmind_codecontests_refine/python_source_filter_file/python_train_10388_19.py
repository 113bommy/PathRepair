from bisect import bisect_left
import sys
sys.setrecursionlimit(1000000)


def dfs(v, p):
    i = bisect_left(dp, a[v])
    dp[i], old = a[v], dp[i]
    ans[v] = bisect_left(dp, INF)-1
    for u in to[v]:
        if u == p:
            continue
        dfs(u, v)
    dp[i] = old

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    to = [[] for _ in range(n)]
    ans = [0]*n
    INF = 10**10
    for _ in range(n-1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        to[u].append(v)
        to[v].append(u)
    dp = [INF]*n
    dp[0] = -INF
    dfs(0, -1)
    print("\n".join(list(map(str, ans))))