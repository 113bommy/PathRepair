read = lambda: map(int, input().split())
n, m = read()
graph = [set() for _ in range(n + 1)]
for __ in range(m):
  u, v = read()
  graph[u].add(v)
  graph[v].add(u)


def find_cycle(start):
  parents, stack = [0] * (n + 1), [(start, +1)]
  while stack:
    vertex, parent = stack.pop()
    parents[vertex] = parent
    for neighbour in graph[vertex]:
      if neighbour != parent:
        if parents[neighbour]:
          cycle = set()
          cycle.add(neighbour)
          while vertex <= neighbour:
            cycle.add(vertex)
            vertex = parents[vertex]
          return cycle
        stack.append((neighbour, vertex))
  return set()


cyc = find_cycle(1)
if not cyc:
  print('NO')
  exit()


def dfs():
  visited = set(cyc)
  for start in cyc:
    stack = [(v, start) for v in graph[start] if v not in cyc]
    while stack:
      vertex, parent = stack.pop()
      visited.add(vertex)
      for neighbour in graph[vertex]:
        if neighbour != parent:
          if neighbour in visited:
            return set()
          stack.append((neighbour, vertex))
  return visited


print('FHTAGN!' if len(dfs()) == n else 'NO')