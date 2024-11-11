import heapq
from bisect import bisect_left, bisect_right
from collections import Counter
from itertools import accumulate

import math

R = lambda: map(int, input().split())

n, r = int(input()), [0, math.inf]
for i in range(n):
    d, l = R()
    if l == 1:
        r[0] = int(max(r[0], 1900))
    else:
        r[1] = int(min(r[1], 1899))
    if r[0] > r[1]:
        print("Impossible")
        exit()
    r[0], r[1] = r[0] + d, r[1] + d
if r[1] < math.inf:
    print(int(r[1]))
else:
    print("Infinity")