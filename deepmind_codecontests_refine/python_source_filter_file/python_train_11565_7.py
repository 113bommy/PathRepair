# -*- coding: utf-8 -*-

import sys
import os
import pprint
from queue import Queue

"""Topological Sort"""

#fd = os.open('GRL_4_B.txt', os.O_RDONLY)
#os.dup2(fd, sys.stdin.fileno())

V, E = list(map(int, input().split()))
G = [[] for i in range(V)]
indig = [0] * V # ??\?¬???°
for i in range(V):
    s, t = list(map(int, input().split()))
    G[s].append(t)
    indig[t] += 1

q = Queue()
out = []

def bfs(node_index):
    q.put(node_index)

    while not q.empty():
        u = q.get()
        out.append(u)

        # u?????????????????§u?????????indig????????????
        for index in G[u]:
            indig[index] -= 1
            if indig[index] == 0:
                q.put(index)

# bfs?????????
indig_copy = indig[:]
for i in range(V):
    if indig_copy[i] == 0:
        bfs(node_index=i)

for v in out:
    print(v)