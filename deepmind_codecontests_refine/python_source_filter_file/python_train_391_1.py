import sys
sys.setrecursionlimit(10**9)

N, u, v = map(int, input().split())
u, v = u-1, v-1
edge = [[] for _ in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    edge[a].append(b)
    edge[b].append(a)

taka = [0] * N
aoki = [0] * N

def dfs(v, pre, cost, i):
    for e in edge[v]:
        if e == pre:
            continue
        cost = dfs(e, v, cost, i+1)
    cost[v] = i
    return cost

taka = dfs(u, -1, [0] * N, 0)
aoki = dfs(v, -1, [0] * N, 0)

m = 0
for i in range(N):
    if taka[i] < aoki[i]:
        m = max(m, taka[i])

print(m)
