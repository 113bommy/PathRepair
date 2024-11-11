from copy import deepcopy
import itertools
from bisect import bisect_left
from bisect import bisect_right
import math
from collections import deque
from collections import Counter


def read():
    return int(input())


def readmap():
    return map(int, input().split())


def readlist():
    return list(map(int, input().split()))


n, h = readmap()
seg = []
c, b = readmap()
seg.append((0, b-c))
for _ in range(n-1):
    a, b = readmap()
    seg.append((a-c, b-c))

cumu = [0] * n
for i in range(1, n):
    cumu[i] = cumu[i-1] + seg[i][0] - seg[i-1][1]

ans = 0
for i in range(n):
    idx = bisect_left(cumu, h + cumu[i])
    if idx < n:
        can = seg[idx][0] - (cumu[idx] - cumu[i] - h) - seg[i][0]
        ans = max(ans, can)
    else:
        can = seg[-1][1] + (h - cumu[-1] + cumu[i]) - seg[i][0]
        ans = max(ans, can)

print(ans)
