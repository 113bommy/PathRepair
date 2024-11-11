import heapq
WHITE = 0
GRAY = 1
BLACK = 2
INFTY = 10**13
def dijkstra(s, VC):
    color = [WHITE for i in range(N)]
    d = [INFTY for i in range(N)]
    d[s] = 0
    pq = []
    heapq.heappush(pq, (0, s))

    while len(pq) != 0:
        u = heapq.heappop(pq)[1]
        color[u] = BLACK

        for v, c in VC[u]:
            if color[v] != BLACK:
                if d[u] + c < d[v]:
                    d[v] = d[u] + c
                    color[v] = GRAY
                    heapq.heappush(pq, (d[v], v))

    return d

N, M, S, T = map(int, input().split())
VA = [[] for i in range(N)]
VB = [[] for i in range(N)]
for i in range(M):
    u, v, a, b = list(map(int, input().split()))
    VA[u-1].append([v-1, a])
    VA[v-1].append([u-1, a])
    VB[u-1].append([v-1, b])
    VB[v-1].append([u-1, b])

da = dijkstra(S-1, VA)
db = dijkstra(T-1, VB)
tmp = 10**16
base = 10 ** 15
ans = [0 for i in range(N)]
for i in range(N-1, -1, -1):
    tmp = min(da[i] + db[i], tmp)
    ans[i] = tmp

for i in range(N):
    print(base - ans[i])
    