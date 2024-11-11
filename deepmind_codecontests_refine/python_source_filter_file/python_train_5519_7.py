# -*- coding: utf-8 -*-
from collections import deque

N = int(input())
adj = [[0]*N for _ in range(N)]
unsearched = set(range(N))
result = {n:-1 for n in range(N)}

for n in range(N):
    inp = list(map(int, input().split()))
    for i in inp[2:]:
        adj[inp[0]-1][i-1] = 1

que = deque([[0, 0]]) # edge distance

while len(que):
    q = que.pop()
    result[q[0]] = q[1]
    next_ = [[i, q[1] + 1] for i, a in enumerate(adj[q[0]]) if (a==1) & (i in unsearched)]
    unsearched = unsearched.difference([i[0] for i in next_])
    que.extendleft(next_)

for n in range(N):
    print("{} {}".format(n+1, result[n]))