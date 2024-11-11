import random
from bisect import bisect_left, bisect_right
from typing import List
import collections
import bisect
import itertools
import functools
from fractions import gcd
import heapq
from math import ceil, sqrt, floor

# import sys
# sys.setrecursionlimit(50000)
from collections import defaultdict, deque

import collections


n,m,d = list(map(int, input().split()))

C = list(map(int, input().split()))

bridge_len = sum(C)

water_len = n - bridge_len

min_water_len = floor(water_len / (m + 1))
max_water_len = ceil(water_len / (m + 1))

if max_water_len <= d:
    print("YES")
    additional_water = water_len % (m+1)
    ret = []
    for i in range(m):
        for j in range(min_water_len):
            ret.append(0)
        if additional_water > 0:
            ret.append(0)
            additional_water -= 1
        for j in range(C[i]):
            ret.append(i+1)
    while len(ret) < n:
        ret.append(0)
    print(' '.join(str(i) for i in ret))

else:
    print("NO")

