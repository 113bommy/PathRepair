#!/usr/bin/env python3

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
sys.setrecursionlimit(2147483647)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n, q = LI()
ans = (n-2) * (n-2)
min_x_list = [-n]
min_x_idx = [0]
min_y_list = [-n]
min_y_idx = [0]
idx = 1
for _ in range(q):
    a, b = LI()
    min_x = -min_x_list[-1]
    min_y = -min_y_list[-1]
    if a == 1:
        if min_x > b:
            min_x_list.append(-b)
            min_x_idx.append(idx)
            idx += 1
            ans -= min_y - 2
        else:
            r = br(min_x_list, -b)
            i = min_x_idx[r]
            r = br(min_y_idx, i)
            ans -= -min_y_list[r-1] - 2

    elif a == 2:
        if min_y > b:
            min_y_list.append(-b)
            min_y_idx.append(idx)
            idx += 1
            ans -= min_x - 2
        else:
            r = br(min_y_list, -b)
            i = min_y_idx[r]
            r = br(min_y_idx, i)
            ans -= -min_x_list[r-1] - 2
print(ans)
