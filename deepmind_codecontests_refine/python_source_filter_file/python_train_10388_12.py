import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7 # 998244353
input=lambda:sys.stdin.readline().rstrip()
from bisect import bisect_left
def resolve():
    n = int(input())
    A = list(map(int,input().split()))
    E = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int,input().split())
        u -= 1; v -= 1
        E[u].append(v)
        E[v].append(u)

    dp = [INF] * (n + 1)
    dp[0] = -INF
    res = 0
    ans = [None] * n
    change = [None] * n
    stack = [(0, -1)]

    while stack:
        v, p = stack.pop()
        if v >= 0:
            idx = bisect_left(dp, A[v])
            change[v] = (idx, dp[idx])
            res = max(res, idx)
            ans[v] = res
            dp[idx] = A[v]
            for nv in E[v]:
                if nv == p:
                    continue
                stack.append((~nv, v))
                stack.append((nv, v))
        else:
            v = ~v
            idx, prev = change[v]
            dp[idx] = prev
            res = dp[p]

    print(*ans)
resolve()