import sys

INF = float('inf')

def Bellmanford(n, edges, r):
    d = [INF] * n
    d[r] = 0
    
    for i in range(n):
        flag = False
        
        for (u, v, c) in edges:
            if d[u] != INF and d[u] + c < d[v]:
                d[v] = d[u] + c
                flag = True
                
        if flag and i == n-1:
            return 'NEGATIVE CYCLE'
        
    d = [di if di < INF else 'INF' for di in d]
    return d

V, E, R = map(int, sys.stdin.readline().split())
Edges = [None] * E

for i in range(E):
    si, ti, di = map(int, sys.stdin.readline().split())
    Edges[i] = (si, ti, di)
    
ans = Bellmanford(V, Edges, R)

print(*ans, sep = '\n')