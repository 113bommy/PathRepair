from collections import deque, defaultdict
import sys

sys.setrecursionlimit(10**8)
N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    a -= 1; b -= 1;
    graph[a].append(b)
    graph[b].append(a)


visited = [False for _ in range(N)]
color = [0 for _ in range(N)]

def dfs(now, c):

    color[now] = c

    for adj in graph[now]:
        if color[adj] == c:
            return False

        if color[adj] == 0 and not dfs(adj, -c):
            return False

    return True

ans = dfs(0, 1)
white = color.count(-1)
black = N - white
if ans:
    print(black * white - M)
else:
    print(N * (N+1)//2 - M)
