from heapq import heappop, heappush
N, M = map(int, input().split())
route_list = [[] for _ in range(N)]
for i in range(M):
    L, R, C = map(int, input().split())
    route_list[L-1].append((R-1, C))
for i in range(N-1):
    route_list[i+1].append((i, 0))

distance = [float("inf")] * N
distance[0] = 0  # 初期のノードの距離は0とする
q = [(0, 0)]

while q:
    _, u = heappop(q)
    for des, cost in route_list[u]:
        if distance[des] > distance[u] + cost:
            distance[des] = distance[u] + cost
            heappush(q, (distance[des], des))

print(distance[-1] if distance[-1] != float("inf") else -1)