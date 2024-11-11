# -*- coding: utf-8 -*-

from math import log2, floor

L = int(input())

N = floor(log2(L)) + 1
edge = []

# 長さ0の辺
for i in range(1, N):
    edge.append((i, i+1, 0))

# 長さ2**(i-1)の辺
for i in range(1, N):
    edge.append((i, i+1, 2**(i-1)))

# ここまでで長さ0,...,X-1のパスが完成
X = 2 ** (N-1)

# 残りの辺
while L > X:
    r = floor(log2(L - X))
    edge.append((r + 1, N, X))
    X += 2 ** r

# 出力
M = len(edge)
print(N, M)
for e in edge:
    print(' '.join(map(str, e)))