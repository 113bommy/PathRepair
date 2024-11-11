import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(m)]
graph = [[] for i in range(n+1)]
for a,b in ab:
  graph[a].append(b)
s,t = map(int,input().split())
visited = [[-1,-1,-1] for i in range(n+1)]
que = deque([(s,0,0)])
while que:
  x,mod,cnt = que.popleft()
  visited[x][mod] = cnt
  if x == t and mod == 0:
    break
  for y in graph[x]:
    if visited[y][(mod+1)%3] == -1:
      que.append((y,(mod+1)%3,cnt+1))
      visited[y][(mod+1)%3] == cnt+1
print(visited[t][0]//3)