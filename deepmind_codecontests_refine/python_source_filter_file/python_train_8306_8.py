N = int(input())
E = [[] for _ in range(N)]
for _ in range(N - 1):
  a, b = map(int, input().split())
  E[a - 1].append(b - 1)
  E[b - 1].append(a - 1)
def dijkstra(s):
  D = [-1] * N
  D[s] = s
  Q = [0] * N
  Q[0] = s
  pos = 1
  for i in range(N):
    v = Q[i]
    for adj in E[v]:
      if D[adj] >= 0:
        continue
      Q[pos] = adj
      pos += 1
      D[adj] = D[v] + 1
  return D
D = dijkstra(0)
_, s = max([[D[i], i] for i in range(N)])
D = dijkstra(s)
L = max(D)
print('First' if L % 3 != 1 else 'Second')