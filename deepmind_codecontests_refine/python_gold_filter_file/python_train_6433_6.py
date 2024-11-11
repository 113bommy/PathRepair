n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
vis = {}
def dfs(i):
    if i in vis:
        return vis[i]
    vis[i] = True
    for j in g[i]:
        if dfs(j):
            return True
    vis[i] = False
    return False
for i in range(n):
    if dfs(i):
        print(0)
        break
else:
    print(-1)