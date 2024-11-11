import sys
sys.setrecursionlimit(10**9)
MOD = 1_000_000_007
N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N - 1):
    x, y = list(map(int, input().split()))
    G[x].append(y)
    G[y].append(x)

def dfs(v, root):
    w, b = 1, 1
    for u in G[v]:
        if u == root:
            continue
        child_w, child_b = dfs(u ,v)
        w *= child_w + child_b
        b *= child_w
    w %= MOD
    b %= MOD
    return w, b

print(sum(dfs(1,None)))