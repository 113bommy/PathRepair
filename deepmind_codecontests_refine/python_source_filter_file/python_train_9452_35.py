def is_reachable(edges,start,end):
  g = {}
  for f,t,w in edges:
    if f in g: g[f].append(t)
    else: g[f] = [t]
  visiting = [start]
  visited = {}
  while visiting:
    v = visiting.pop()
    if v in visited: continue
    if v == end: return True
    visited[v] = True
    for v2 in g.get(v, ()):
      if v2 in visited or v2 in visiting: continue
      visiting.append(v2)
  return False

N,M,P = map(int, input().split())

edges = []
for _ in range(M):
    a,b,c = map(int, input().split())
    edges.append((a,b,c))

neg_inf = float("-Inf")
no_answer = False

start = 1
end = N

distance = {}
for i in range(1,N+1):
  distance[i] = neg_inf
distance[start] = 0

for i in range(N-1):
    for f,t,w in edges:
        if distance[f] + w - P > distance[t]:
            distance[t] = distance[f] + w - P

for f,t,w in edges:
    if distance.get[f] + w - P > distance[t] and is_reachable(edges,t,end):
        no_answer = True
        break

if no_answer:
    print(-1)
else:
    print(max(0,distance[end]))
