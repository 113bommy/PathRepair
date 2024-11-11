from heapq import heappush, heappop
inf = float('inf')
def dijkstra(graph:list, node:int, start:int) -> list:
    dist = [inf]*node

    dist[start] = 0
    heap = [(0,start)]
    while heap:
        cost,thisNode = heappop(heap)
        for NextCost,NextNode in graph[thisNode]:
            dist_cand = dist[thisNode]+NextCost
            if dist_cand < dist[NextNode]:
                dist[NextNode] = dist_cand
                heappush(heap,(dist[NextNode],NextNode))
    return dist

N,M,S = map(int,input().split())
graph = [[] for i in range(2501*N)]
for i in range(M):
    u,v,a,b = map(int,input().split())
    u -= 1
    v -= 1
    for s in range(a,2500):
        graph[2501*u+s].append([b,2501*v+s-a])
        graph[2501*v+s].append([b,2501*u+s-a])

for i in range(N):
    c,d = map(int,input().split())
    for s in range(2500):
        graph[2501*i+s].append([d,2501*i+min(2500,s+c)])

dist = dijkstra(graph,2501*N,min(2500,S))

ans = [inf]*N
for i in range(N):
    for s in range(2501):
        ans[i] = min(ans[i],dist[2500*i+s])

for i in range(1,N):
    print(ans[i])