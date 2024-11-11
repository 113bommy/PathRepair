import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

used = [0]*N
Q1 = []
Q2 = []
def dfs(v, Q):
    if used[v]:
        return 0
    used[v] = 1
    Q.append(v+1)
    for w in G[v]:
        if dfs(w, Q):
            return 1
    return 1

if len(G[0]) == 1:
    dfs(0, Q1)
    print(len(Q1))
    print(*Q1)
else:
    used[0] = 1
    for v in G[0]:
        if dfs(v, Q1):
            break
    for v in G[0]:
        if dfs(v, Q2):
            break
    print(len(Q1) + len(Q2) + 1)
    print(*Q1[::-1], 1, *Q2)
