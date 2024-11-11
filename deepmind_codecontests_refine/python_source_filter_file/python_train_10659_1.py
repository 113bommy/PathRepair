import math
import sys
from bisect import bisect_right, bisect_left, insort_right
from collections import Counter, defaultdict
from heapq import heappop, heappush
from itertools import accumulate, permutations
from sys import stdout

R = lambda: map(int, input().split())
n, s = R()
seq = [0] + list(R())
incm = [0] * (n + 1)
for x in seq:
    if x:
        incm[x] = 1
sz = [0] * (n + 1)
st = []
bs = 1
x = s
while seq[x]:
    bs += 1
    x = seq[x]
for i, x in enumerate(incm):
    foundx = False
    if not x:
        l = i
        while i:
            foundx = foundx or i == s
            sz[l] += 1
            i = seq[i]
        if seq[l] and not foundx:
            st.append(sz[l])
nz = seq.count(0) - 1 - len(st) - 1
pos = [0] * (n + 1)
for p in st:
    for i in range(n + 1):
        if bs + i + p < n + 1 and pos[bs + i]:
            pos[bs + i + p] = 1
    pos[bs + p] = 1
rp = [0] * (n + 1)
rp[bs] = 1
if bs + nz + 1 < n + 1:
    rp[bs + nz + 1] = -1
for i in range(n + 1):
    if pos[i]:
        rp[i] += 1
        if i + nz + 1 < n + 1:
            rp[i + nz + 1] -= 1
for i in range(1, n + 1):
    rp[i] += rp[i - 1]
for i in range(1, n + 1):
    if rp[i]:
        print(i)