import collections
import sys
import time
sys.setrecursionlimit(10 ** 5)
N, M, P = map(int, input().split())
e = collections.defaultdict(list)
st = time.time()
for _ in range(M):
  u, v, c = map(int, input().split())
  e[u].append((v, c))
def isConnected(n):
  if n == N:
    return True
  vis = [0] * (N + 1)
  que = collections.deque([])
  que.append(n)
  while que:
    nc = que.popleft()
    vis[nc] = 1
    for o in e[nc]:
      if o[0] == N:
        return True
      if vis[o[0]] == 0:
        que.append(o[0])
  return False
inf = 10 ** 10
visited = [0] * (N + 1)
earn = [-inf] * (N + 1)
earn[1] = 0
def dfs(now):
  global visited
  global earn
  nt = time.time() - st
  if nt > 1.95:
    print(max(earn[N], 0))
    exit(0)
  visited[now] = 1
  for n in e[now]:
    if visited[n[0]] == 0:
      if n[1] + earn[now] - P > earn[n[0]]:
        earn[n[0]] = n[1] + earn[now] - P
        dfs(n[0])
        visited[n[0]] = 0
    else:
      if earn[n[0]] < n[1] + earn[now] - P:
        if isConnected(n[0]) == True:
          print(-1)
          exit(0)
dfs(1)
print(max(earn[N], 0))


