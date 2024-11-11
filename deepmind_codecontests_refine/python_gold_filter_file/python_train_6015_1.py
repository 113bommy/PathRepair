import sys

input = sys.stdin.readline

sys.setrecursionlimit(5*10**5)

N,M = map(int,input().split())
edge = [[] for i in range(N)]
rev_edge = [[] for i in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    edge[a].append(b)
    rev_edge[b].append(a)

seen = [False]*N
stop = []

def dfs(v):
    for nv in edge[v]:
        if not seen[nv]:
            seen[nv]=True
            dfs(nv)
    stop.append(v)

for i in range(N):
    if not seen[i]:
        seen[i] = True
        dfs(i)

seen = [False]*N

def scc():
    res = []
    connect = []
    def rev_dfs(v):
        for nv in rev_edge[v]:
            if not seen[nv]:
                connect.append(nv)
                seen[nv]=True
                rev_dfs(nv)

    while stop:
        while stop and seen[stop[-1]]:
            stop.pop()
        if not stop:
            break
        connect = [stop[-1]]
        seen[stop[-1]] = True
        rev_dfs(stop[-1])
        res.append(connect)
    return res

res = scc()
print(len(res))
for L in res:
    print(len(L),*L)
