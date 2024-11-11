import sys
import bisect
sys.setrecursionlimit(10**9)
INF = 2**30
N = int(input())
A = list(map(int, input().split()))
E = []
for i in range(N):
    E.append([])
for i in range(N-1):
    u, v = list(map(int, input().split()))
    u -= 1
    v -= 1
    E[u].append(v)
    E[v].append(u)

ans = [0] * N
dp = [INF] * N

def dfs(now, par, len):
    ok = bisect.bisect_right(dp, A[now])
    memo = dp[ok]
    dp[ok] = A[now]

    ok1 = bisect.bisect_left(dp, INF)
    ans[now] = ok1

    for to in E[now]:
        if to == par:
            continue
        dfs(to, now, len+1)
    dp[ok] = memo

dfs(0, -1, 0)

for i in range(N):
    print(ans[i])
