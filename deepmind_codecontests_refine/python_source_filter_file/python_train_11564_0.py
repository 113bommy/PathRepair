from sys import stdin
from collections import deque
V, E = map(int, stdin.readline().split())
adj_list = [[] for _ in [] * V]
is_visited = [False] * V
for _ in [0] * E:
    s, t = map(int, stdin.readline().split())
    adj_list[s].append(t)
out = deque()
def dfs(u):
    is_visited[u] = True
    for v in adj_list[u]:
        if not is_visited[v]:
            dfs(v)
    out.appendleft(u)
for s in range(V):
    if not is_visited[s]:
        dfs(s)
print(*out, sep='\n')