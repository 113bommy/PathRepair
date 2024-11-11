#!/usr/bin/env python3

from queue import PriorityQueue

N = int(input())

v = list()
Q = list()

for i in range(N):
    s, k = input().split()
    v.append((int(s), int(k)))
    if int(s) == 1:
        Q.append(i)

edge = list()

while len(Q) > 0:
    u = Q.pop()
    if v[u][0] == 0:
        continue
    g = v[u][1]
    edge.append((i, g))
    v[g] = (v[g][0] - 1, v[g][1] ^ u)
    if v[g][0] == 1:
        Q.append(g)

print(len(edge))
for i, j in edge:
    print(i, j)

