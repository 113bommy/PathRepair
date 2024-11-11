from collections import deque
n = int(input())
e = [[] for _ in range(n)]
AB = [list(map(int, input().split())) for _ in range(n - 1)]
AB = [(a -1, b - 1) for a, b in AB]

for itr, (a, b) in enumerate(AB):
  e[a].append(b)
  e[b].append(b)
  
colors = [-1] * n

# ２色で塗分けする。
q = deque()
# 現在見ている頂点、親の色
q.append((0, 0))
while q:
  v, pcol = q.popleft()
  # 親と異なる色で塗る。
  if colors[v] == -1:
    col = not pcol
    colors[v] = col
    for i in e[v]:
      if colors[i] == -1:
        q.append((i, col))

# print(e)
# print(colors)
        
m = [deque([i for i in range(1, n + 1) if i % 3 == j]) for j in range(3)]

# print(m)

def opop(n, ne):
  if m[n]:
    p = m[n].pop()
  else:
    if n == 1 or n == 2:
      if m[ne]:
        p = m[ne].pop()
      else:
        p = m[0].pop()
    else:
      if m[1]:
        p = m[1].pop()
      else:
        p = m[2].pop()
  return p

ans = [0] * n

if sum(colors) <= len(m[0]):
  for itr, i in enumerate(colors):
    if i:
      ans[itr] = opop(0, 0)
    else:
      ans[itr] = opop(1, 2)
elif sum(colors) >= len(m[1]) + len(m[2]):
  for itr, i in enumerate(colors):
    if not i:
      ans[itr] = opop(0, 0)
    else:
      ans[itr] = opop(1, 2)
else:
  for itr, i in enumerate(colors):
    if i:
      ans[itr] = opop(1, 0)
    else:
      ans[itr] = opop(2, 0)
print(*ans)