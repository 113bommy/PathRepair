import sys
input = sys.stdin.readline
n = int(input())
ab = [list(map(int,input().split())) for i in range(n-1)]
graph = [[] for i in range(n+1)]
for a,b in ab:
  graph[a].append(b)
  graph[b].append(a)
def dfs(root):
  dist = [-1]*(n+1)
  dist[root] = 0
  stack = [root]
  while stack:
    x = stack.pop()
    for y in graph[x]:
      if dist[y] == -1:
        dist[y] = dist[x]+1
        stack.append(y)
  return dist
d = dfs(1)
far = d.index(max(d))
diam = max(dfs(far))
if diam%4 in (1,2):
  print("First")
else:
  print("Second")