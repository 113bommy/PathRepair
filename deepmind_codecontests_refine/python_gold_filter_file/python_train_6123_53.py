import sys
sys.setrecursionlimit(10**9)

N = int(input())
MOD = 10**9+7
G = [set() for _ in range(N)]
for i in range(N-1):
    x, y = map(lambda x: int(x)-1, input().split())
    G[x].add(y)
    G[y].add(x)

def dfs(v, r):
    w, b = 1, 1
    for u in G[v]:
        if u == r: continue
        c_w, c_b = dfs(u, v)
        w *= c_w + c_b
        b *= c_w
    w %= MOD
    b %= MOD
    return w, b

print(sum(dfs(0, None))%MOD)