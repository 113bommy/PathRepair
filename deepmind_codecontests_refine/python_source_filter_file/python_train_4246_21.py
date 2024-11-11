from collections import deque

N, M = map(int, input().split())
g = {i:set() for i in range(N)}
v = [-1 for i in range(N)]
for _ in range(M):
  a, b = map(int, input().split())
  a, b = a-1, b-1
  g[a].add(b)
  g[b].add(a)

Q = deque()
ans = 0
for a in g:
  if v[a]==-1:
    v[a] = 1
    ans_tmp = 1
    Q.append(a)
    while len(Q)>0:
      na = Q.popleft()
      for nb in g[a]:
        if v[nb] == -1:
          v[nb] = 1
          ans_tmp += 1
          Q.append(nb)
    ans = max(ans, ans_tmp)
print(ans)