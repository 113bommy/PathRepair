# -*- coding: utf-8 -*-

import sys
import os
import math

N = int(input())

E = []
E.append([])
d = [None] * (N + 1)

for i in range(N):
    lst = list(map(int, input().split()))
    nodes = lst[2:]
    E.append(nodes)
#print(E)

q = []
q.append(1)

visited = [False] * (N + 1)
d[1] = 0
visited[1] = True

while q:
    index = q.pop(0)

    # ???????????????????????´???
    for v in E[index]:
        if not visited[v]:
            q.append(v)
            d[v] = d[index] + 1
            visited[v] = True

#print(d)
for i in range(1, N + 1):
    print(i, d[i])