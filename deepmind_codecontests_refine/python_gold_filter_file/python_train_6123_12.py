from sys import setrecursionlimit
setrecursionlimit(10 ** 6)

mod = 10 ** 9 + 7

N, *XY = map(int, open(0).read().split())

E = [[] for _ in range(N + 1)]
for x, y in zip(*[iter(XY)] * 2):
    E[x].append(y)
    E[y].append(x)

def dfs(cur, par):
    w, b = 1, 1
    for nxt in E[cur]:
        if nxt == par:
            continue
        ww, bb = dfs(nxt, cur)
        w = (w * (ww + bb)) % mod
        b = (b * ww) % mod
    return (w, b)

print(sum(dfs(1, -1)) % mod)