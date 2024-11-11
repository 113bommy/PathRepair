import bisect
import collections
import copy
import functools
import heapq
import itertools
import math
import random
import re
import string
import sys
import time
from typing import Counter, List

sys.setrecursionlimit(99999)

input()
mx = 10**5 + 5
f = [0] * mx
f[1] = 1
for i in range(2, mx):
    if f[i] == 0:
        f[i] = i
        for j in range(i * i, mx, i):
            if f[j] == 0:
                f[j] = i
mp = collections.defaultdict(int)
for c in map(int, input().split()):
    p = []
    while f[c] != c:
        k = f[c]
        p.append(k)
        while c % k == 0:
            c //= k
    if c > 1:
        p.append(c)
    if p:
        mx = max(mp[x] for x in p)
        for c in p:
            mp[c] = mx + 1
if mp:
    print(max(mp.values()))
else:
    print(1)