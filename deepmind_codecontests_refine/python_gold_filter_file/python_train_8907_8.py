import math
from bisect import bisect_right, bisect_left
from collections import Counter
from heapq import heappop, heappush
from itertools import accumulate

R = lambda: map(int, input().split())
mi, mx = R()
g = math.gcd(mi, mx)
res = []
for x in range(1, int(math.sqrt(g)) + 1):
    if g % x == 0:
        res.append(x)
        res.append(g // x)
res.sort()
for x in range(int(input())):
    l, r = R()
    i = bisect_right(res, r) - 1
    if l <= res[i] <= r:
        print(res[i])
    else:
        print(-1)