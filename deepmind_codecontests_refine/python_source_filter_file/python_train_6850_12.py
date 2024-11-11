N, M = [int(i) for i in input().split()]
UVm = [[int(i) for i in input().split()] for _ in range(M)]
S, T = [int(i) for i in input().split()]

graphs = [[] for _ in range( 3 * N)]
dists = [-1 for _ in range( 3 * N)]
for uv in UVm:
  u = uv[0] - 1
  v = uv[1] - 1
  graphs[u].append(v + N)
  graphs[u + N].append( v + 2 * N)
  graphs[u + 2 * N].append(v)
  
from collections import deque
que = deque()
que.append(S - 1)
dists[S - 1] = 0
while len(que) > 0:
  nex = que.pop()
  for edge in graphs[nex]:
    if dists[edge] != -1:
      continue
    que.append(edge)
    dists[edge] = dists[nex] + 1
print(dists[T-1] // 3)

