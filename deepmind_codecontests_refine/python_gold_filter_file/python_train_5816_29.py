from collections import defaultdict
import heapq
from math import sqrt
# -*- coding: utf-8 -*-
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def calc(b1, b2):
    x1, y1, r1 = b1
    x2, y2, r2 = b2
    d = sqrt((x1-x2)**2+(y1-y2)**2)
    return max(d-(r1+r2), 0)


sx, sy, gx, gy = map(int, input().split())
N = int(input())
barriers = [[sx, sy, 0]] + [list(map(int, input().split()))
                            for _ in range(N)]+[[gx, gy, 0]]

mat = [[0]*(N+2) for _ in range(N+2)]

for row in range(N+2):
    for col in range(row+1, N+2):
        d = calc(barriers[row], barriers[col])
        mat[row][col] = d
        mat[col][row] = d

# 視点からの距離
dist = [float('inf')]*(N+2)
dist[0] = 0

# 最短経路での一つ前のノード
prev = defaultdict(lambda: None)

Q = []
# Q->[dist from　start,node])
heapq.heappush(Q, (0, 0))

while Q:
    dist_to_node, node = heapq.heappop(Q)
    if dist[node] < dist_to_node:
        continue
    else:
        for v in range(N+2):
            weight = mat[node][v]
            alt = dist_to_node+weight
            if dist[v] > alt:
                dist[v] = alt
                prev[v] = node
                heapq.heappush(Q, (alt, v))
print(dist[-1])
