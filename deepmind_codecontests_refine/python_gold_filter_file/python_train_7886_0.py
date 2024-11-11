import sys
sys.setrecursionlimit(2 * (10 ** 6))
n, m = map(int, input().split())
edges = [[] for i in range(n)]
visit = [False for i in range(n)]
def dfs(v):
    visit[v] = True
    for i in edges[v]:
        if not visit[i]:
            dfs(i)
for i in range(m):
    a, b = map(int, input().split())
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)
cnt = 0
for i in range(n):
    if not visit[i]:
        dfs(i)
        cnt += 1
print(cnt - 1)