import sys

sys.setrecursionlimit(100005)
MOD = 1000000007


def dfs(v, a):
    w, b = 1, 1
    for u in links[v]:
        if u == a:
            continue
        cw, cb = dfs(u, v)
        w *= cw + cb
        b *= cw
        w %= MOD
        b %= MOD
    return w, b


n = int(input())
links = [set() for _ in range(n)]
for line in sys.stdin.readlines():
    x, y = map(int, line.split())
    x -= 1
    y -= 1
    links[x].add(y)
    links[y].add(x)

print(sum(dfs(0, None)))
