from sys import stdin

input = stdin.readline
from heapq import heappush, heappop

n, m, k = map(int, input().split())
# edge = [tuple(map(int, input().split())) for _ in range(m)]
# courier = [tuple(map(int, input().split())) for _ in range(k)]
r = [tuple(map(int,inp.split())) for inp in stdin.read().splitlines()]

adj = [[] for _ in range(n+1)]
for u, v, w in r[:m]:
    adj[u].append([v, w])
    adj[v].append([u, w])
INF = 10 ** 7
dis = [[INF] * (n + 1) for _ in range(n + 1)]
# for i in range(1,n+1):
#     dis[i][i] = 0
for s in range(1, n + 1):
    dis[s][s] = 0
    h = [(0, s)]
    while h:
        curd, cur = heappop(h)
        if curd > dis[s][cur]:
            continue
        for nxt, w in adj[cur]:
            nd = curd + w
            if nd < dis[s][nxt]:
                dis[s][nxt] = nd
                heappush(h, (nd, nxt))
res = INF
for s, e, _ in r[:m]:
    temp = 0
    for cs, ce in r[m:]:
        temp += min(dis[cs][ce], dis[cs][s] + dis[ce][e], dis[cs][e] + dis[ce][s])
    res = min(res,temp)
print(res)
