import sys

input = sys.stdin.readline
sys.setrecursionlimit(200010)
n = int(input())
info = [list(map(int, input().split())) for i in range(n)]

v = 100000
graph = [[] for i in range(v*2)]
for i in range(n):
    x = info[i][0] - 1
    y = (info[i][1] - 1) + v
    graph[x].append(y)
    graph[y].append(x)

def dfs(pos):
    if visited[pos]:
        return
    visited[pos] = True
    cnt[pos//v] += 1
    for i in graph[pos]:
        dfs(i)
    return

visited = [False] * (v*2)
cnt = [0]*2
ans = 0
for i in range(v*2):
    cnt[0] = 0
    cnt[1] = 0
    dfs(i)
    ans += cnt[0]*cnt[1]
print(ans - n)
