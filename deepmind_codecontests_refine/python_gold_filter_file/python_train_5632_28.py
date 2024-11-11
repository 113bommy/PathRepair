import math
from bisect import bisect_right, bisect_left
from collections import Counter
from heapq import heappop, heappush
from itertools import accumulate

R = lambda: map(int, input().split())
n, m = R()
cnts = list(Counter(R()).values())
l, r = 0, m
while l < r:
    mid = (l + r + 1) // 2
    sp = sum(x // mid for x in cnts)
    if sp >= n:
        l = mid
    else:
        r = mid - 1
print(l)