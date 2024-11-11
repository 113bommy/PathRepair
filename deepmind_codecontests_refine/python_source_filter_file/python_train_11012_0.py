import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.buffer.readline().rstrip()
from bisect import bisect_left, bisect_right
def resolve():
    n, m = map(int, input().split())
    AB = [list(map(int, input().split())) for _ in range(n)]
    AB.sort()
    AB.append([INF, 0])
    for i in range(n, 0, -1):
        AB[i][1] ^= AB[i - 1][1]

    E = [[] for _ in range(n + 1)]
    for i in range(m):
        u, v = map(int, input().split())
        l = bisect_left(AB, [u, 0])
        r = bisect_right(AB, [v, 1])
        E[l].append((r, i + 1))
        E[r].append((l, i + 1))

    ans = []
    used = [False] * (n + 1)
    def dfs(v):
        used[v] = True
        res = AB[v][1]
        for nv, i in E[v]:
            if used[nv]:
                continue
            r = dfs(nv)
            if r:
                ans.append(i)
            res ^= r
        return res

    for v in range(n + 1):
        if used[v]:
            continue
        if dfs(v):
            print(-1)
            return

    print(len(ans))
    if ans:
        print(*sorted(ans))
resolve()