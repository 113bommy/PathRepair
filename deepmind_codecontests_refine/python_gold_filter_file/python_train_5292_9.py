# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest094 e問題 未完成
Author     : Kitaura Hiromi
LastUpdate : 20180420
Since      : 20180414
"""
inf = 10**20
# 最終的に, 1組以外はすべて0になる
N = int(input())
s = 0
m = inf
for i in range(N):
    a, b = map(int, input().split(" "))
    if a > b:
        if m > b:
            m = b
    s += a
if m == inf:
    print(0)
else:
    print(s - m)