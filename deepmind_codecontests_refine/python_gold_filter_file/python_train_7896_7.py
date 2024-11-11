import sys
input = sys.stdin.readline
from collections import defaultdict

"""
(駅、会社)を頂点にグラフを持つ。頂点数O(M)。
そのまま辺を貼ると辺が多くなりすぎる。
(駅、会社) -> (駅、無属性) -> (駅、会社)
"""

L = 32
mask = (1 << L) - 1
N,M = map(int,input().split())
graph = defaultdict(list)
for _ in range(M):
    p,q,c = map(int,input().split())
    p <<= L
    q <<= L
    graph[p].append(p+c)
    graph[p+c].append(p)
    graph[q].append(q+c)
    graph[q+c].append(q)
    graph[p+c].append(q+c)
    graph[q+c].append(p+c)

INF = 10 ** 9
dist = defaultdict(lambda: INF)

start = 1 << L
goal = N << L

q = [start] # 0 が会社に属していない状態
dist[start] = 0
d = 0
while q:
    qq = []
    while q:
        x = q.pop()
        if x & mask == 0:
            for y in graph[x]:
                if dist[y] <= d + 1:
                    continue
                dist[y] = d + 1
                qq.append(y)
        else:
            for y in graph[x]:
                if dist[y] <= d:
                    continue
                dist[y] = d
                q.append(y)
    d += 1
    q = qq

answer = dist[goal]
if answer == INF:
    answer = -1
print(answer)