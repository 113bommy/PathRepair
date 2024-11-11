def dfs():
    tt = 0
    for u in range(N):
        if colors[u] == WHITE:
            dfs_visit(u, tt)

def dfs_visit(u, tt):
    tt += 1
    colors[u] = GLAY
    d[u] = tt
    for v in range(N):
        if adjacency_list[u][v] == 1 and colors[v] == WHITE:
            tt = dfs_visit(v, tt)
    tt += 1
    colors[u] = BLACK
    f[u] = tt
    return tt


N = int(input())
adjacency_list = [[0 for j in range(N)] for i in range(N)]
for _ in range(N):
    u, k, *v = map(int, input().split())
    for i in v:
        adjacency_list[u-1][i-1] = 1

WHITE = 0
GLAY = 1
BLACK = 2
colors = [WHITE for _ in range(N)]
d = [0 for _ in range(N)]
f = [0 for _ in range(N)]


dfs()

for i in range(N):
    print("{} {} {}".format(i+1, d[i], f[i]))
