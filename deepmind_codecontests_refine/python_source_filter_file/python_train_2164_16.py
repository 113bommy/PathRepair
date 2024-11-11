import heapq
INF = 10**10

N, M, S = map(int, input().split())
adj = [[] for _ in range(N)]
for m in range(M):
    u,v,a,b = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append((v,a,b))
    adj[v].append((u,a,b))

C = []
D = []
for n in range(N):
    c, d = map(int, input().split())
    C.append(c)
    D.append(d)

M = 2500
S = min(S, M-1) # 2500枚あれば十分
dist = [[INF]*M for _ in range(N)] # dist[都市][銀貨の枚数]
dist[0][S] = 0
q = [(0,S,0)] # (距離、銀貨の枚数、都市)

while q:
    d, sil, node = heapq.heappop(q)
    if dist[node][sil] < d: # 探索の対象にする必要があるか確認
        continue 
    if sil+C[node] < M and d+D[node] < dist[node][sil+C[node]]:
        dist[node][sil+C[node]] = d + D[node]
        heapq.heappush(q, (d + D[node], sil+C[node] ,node))
    for to,a,b in adj[node]:
        if sil >= a and d + b < dist[to][sil-a]:
            dist[to][sil-a] = d + b
            heapq.heappush(q, (d + b, sil-a ,to))

for i in range(1,N):
    print(min(dist[i]))

