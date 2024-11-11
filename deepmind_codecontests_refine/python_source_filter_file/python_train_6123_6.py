import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

mod = 10**9+7
N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    x, y = map(int, input().split())
    G[x].append(y)
    G[y].append(x)
black = [1] * (N+1)
white = [1] * (N+1)

def dfs(prev, u):
    for v in G[u]:
        if v == prev:
            continue
        dfs(u, v)
        black[u] *= white[v]
        black[u] %= mod
        white[u] *= black[v] + white[v]
        white[u] %= mod

dfs(0, 1)
print(black[1] + white[1])

