def findSet(u):
  if parent[u] != u:
    parent[u] = findSet(parent[u])
  return parent[u]

def unionSet(u, v):
  up = findSet(u)
  vp = findSet(v)
  if up == vp:
    return
  if ranks[up] > ranks[vp]:
    parent[vp] = up
  elif ranks[up] < ranks[vp]:
    parent[up] = vp
  else:
    parent[up] = vp
    ranks[vp] += 1

n, m = map(int, input().split())
mapping = {}
graph = [None] * n
for i in range(n):
  this_emp = list(map(int, input().split())) 
  # mapping[i] = this_emp[1:]
  if this_emp[0] == 0:
    graph[i] = []
  else:
    graph[i] = this_emp[1:]
print(graph)


parent = [i for i in range(n)]
ranks = [0 for i in range(n)]
# cost = n

for i in range(len(graph)):
  for j in range(i + 1, len(graph)):
    if ((set(graph[i]) & set(graph[j]))):
      unionSet(i, j)
      # cost = cost - 1

# print(cost)
cost = 0
for p in range(len(parent)):
  if p == parent[p]:
    cost += 1

print(parent)
empty = 0
for i in range(len(graph)):
  if len(graph[i]) == 0:
    empty += 1
if empty == n:
  print(n)
else:
  print(cost - 1)