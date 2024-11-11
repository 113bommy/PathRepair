import heapq

nv, ne = map(int, input().split())

edges = [set() for _ in range(nv)]
while ne:
    s, t, w = map(int, input().split())
    edges[s].add((w, t))
    edges[t].add((w, s))
    ne -= 1

cost = 0
queue = list(edges[0])
heapq.heapify(queue)
visited = [False] * nv
visited[0] = True

while True:
    edge_cost, t = heapq.heappop(queue)
    if visited[t]:
        continue
    visited[t] = True
    cost += edge_cost
    if all(visited):
        break
    for e in edges[t]:
        if not visited[e[1]]:
            heapq.heappush(queue, e)

print(cost)