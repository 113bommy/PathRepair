#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**6)


def dfs(s):
    for t in g[s]:
        if dist[t] > -1:
            if (dist[s] + 1 - dist[t]) % 2 == 1:
                print(-1)
                exit()
            continue
        dist[t] = dist[s] + 1
        dfs(t)


n = int(input())
s = [list(input()) for _ in range(n)]
g = [[] for _ in range(n)]
mat = [[10**9] * n for _ in range(n)]
for i in range(n):
    mat[i][i] = 0
    for j in range(i + 1, n):
        if s[i][j] == '1':
            g[i].append(j)
            g[j].append(i)
            mat[i][j] = mat[j][i] = 1
dist = [-1] * n
dist[0] = 0
dfs(0)

for k in range(n):
    for i in range(n):
        for j in range(n):
            mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])
ans = 0
for i in range(n):
    for j in range(n):
        ans = max(ans, mat[i][j])
print(ans + 1)
