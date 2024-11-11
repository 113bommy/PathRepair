#! /usr/bin/python
# -*- coding:utf-8 -*-

N, W = map(int, input().split())
vs = []
ws = []
for i in range(N):
    v, w = map(int, input().split())
    vs.append(v)
    ws.append(w)

dp = dict()
dp[0] = 0
max_v = -1
for i in range(N):
    tmp = dp.copy()
    for k, v in tmp.items():
        dp.setdefault(k+vs[i], float('inf'))
        dp[k+vs[i]] = min(v + ws[i], dp[k+vs[i]])
        if dp[k+vs[i]] <= W:
            max_v = max(max_v, k+vs[i])

#print(dp)
print(max_v)
