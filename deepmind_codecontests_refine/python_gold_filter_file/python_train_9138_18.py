n = int(input())
S = [list(map(int,input())) for i in range(n)]
Graph = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        if S[i][j]==1:
            Graph[i]+=[j]
colors = [0 for i in range(n)]

def is_bipartite(es):
    stack = [(0,1)]
    while stack:
        v,color = stack.pop()
        colors[v] = color
        for to in es[v]:
            if colors[to] == color:
                 return False
            if colors[to] == 0:
                 stack.append((to, -color))
    return True

if not is_bipartite(Graph):
    print(-1)
    exit()

S2 = [[float("inf") for i in range(n)] for i in range(n)]
for i in range(n):
    for j in range(n):
        if S[i][j]==1:
            S2[i][j]=1
        elif i==j:
            S2[i][j]=0

def warshall_floyd(d):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j],d[i][k] + d[k][j])
    return d

warshall_floyd(S2)

diam = 0
for i in range(n):
    for j in range(n):
        diam = max(diam,S2[i][j])
print(diam+1)