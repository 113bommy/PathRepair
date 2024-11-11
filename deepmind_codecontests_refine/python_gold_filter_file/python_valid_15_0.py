md = int(1e9) + 7
N = 110


def add(x, y):
    x += y
    if x >= md:
        x -= md
    if x < 0:
        x += md
    return x


def mul(x, y):
    x *= y
    x %= md
    return x


depth = [0] * N
cnt = [0]
g = [[] for _ in range(N)]


def Dfs(v, pr):
    for to in g[v]:
        if to != pr:
            depth[to] = depth[v] + 1
            cnt[depth[to]] += 1
            Dfs(to, v)


def solve(n, k, v):
    dp = [[1] + k * [0] for _ in range(n)]
    depth[v] = 0
    res = 0
    for to in g[v]:
        global cnt
        cnt = [0] * n
        depth[to] = 1
        cnt[depth[to]] += 1
        Dfs(to, v)
        # print(cnt)
        for dep in range(n):
            for ct in reversed(range(k)):
                dp[dep][ct + 1] = add(dp[dep][ct + 1],
                                      mul(dp[dep][ct], cnt[dep]))
        # print(n, k, v, cnt, dp)
    for i in range(n):
        res = add(res, dp[i][k])
    return res


t = int(input())
for _ in range(t):
    input()
    n, k = map(int, input().split())
    for i in range(n):
        g[i].clear()
    for i in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    if k == 2:
        print(int((n * (n - 1) / 2) % md))
        continue

    ans = 0
    for i in range(n):
        ans = add(ans, solve(n, k, i))
    print(ans)
