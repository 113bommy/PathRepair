import sys
sys.setrecursionlimit(2*10**5)

n, u, v = map(int, input().split())
edge = [tuple(map(int, input().split())) for _ in range(n-1)]
u -= 1
v -= 1

connect = [set() for _ in range(n)]
for a, b in edge:
    connect[a-1].add(b-1)
    connect[b-1].add(a-1)

du = [0] * n
dv = [0] * n

def dfs(v, dis, ng, d):
    d[v] = dis
    ng.add(v)
    for w in connect[v]:
        if w not in ng:
            dfs(w, dis+1, ng, d)

dfs(u, 0, set(), du)
dfs(v, 0, set(), dv)

ans = 0
for i in range(n):
    if du[i] < du[i]:
        ans = max(ans, du[v]-1)
print(ans)