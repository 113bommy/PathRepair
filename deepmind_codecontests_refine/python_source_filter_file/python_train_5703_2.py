#!/usr/bin/env python3
import sys
rl = sys.stdin.buffer.readline
INF = sys.maxsize

N = int(rl())
PS = [tuple(map(int, rl().split())) for i in range(N)]

def bitcount(n):
  n = n - ((n >> 1) & 0x5555555555555555)
  n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333)
  n = (n + (n >> 4)) & 0x0f0f0f0f0f0f0f0f
  n = n + (n >> 8)
  n = n + (n >> 16)
  n = n + (n >> 32)
  return n & 0x0000007f

def subsets(s):
  t = s
  while t >= 0:
    t &= s
    yield t
    t -= 1

# (x|y)cost[i][j] := 頂点の集合 i に路線が引かれているとき、j 番目の集落から路線までの最小距離
xcost = [[INF] * N for _ in range(1 << N)]
ycost = [[INF] * N for _ in range(1 << N)]
for i in range(1 << N):
  for j in range(N):
    xcost[i][j] = abs(PS[j][0])
    ycost[i][j] = abs(PS[j][1])
    for k in range(N):
      if ((i >> k) & 1) == 1:
        xcost[i][j] = min(xcost[i][j], abs(PS[j][0] - PS[k][0]))
        ycost[i][j] = min(ycost[i][j], abs(PS[j][1] - PS[k][1]))

# 計算結果の距離を歩行距離(= 距離 * 人口)にする
for i in range(1 << N):
  for j in range(N):
    xcost[i][j] = xcost[i][j] * PS[j][2]
    ycost[i][j] = ycost[i][j] * PS[j][2]

# x, y 座標に引かれた線路の引き方の組み合わせの中から最もコストが小さくなるものを求める
ans = [INF] * (N + 1)
for i in range(1 << N):
  size = bitcount(i)
  for j in subsets(i):
    cost = 0
    for k in range(N):
      # i に含まれていない頂点を合計する(i に含まれている頂点の歩行距離は常に０なので)
      if ((i >> k) & 1) == 0:
        cost += min(xcost[j][k], ycost[i-j][k])

    ans[size] = min(ans[size], cost)

# 結果出力
for a in ans:
  print(a)