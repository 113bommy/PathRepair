# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import itertools
import sys

"""
created by shhuan at 2018/12/9 20:21

"""

N = int(input())
A = input()


i = 0
segs = []
while i < N:
    if A[i] == 'G':
        j = i + 1
        while j < N and A[j] == 'G':
            j += 1
        segs.append((i, j))
        i = j
    else:
        i += 1


def seglen(seg):
    return seg[1] - seg[0]


ans = 0
if not segs:
    pass
elif len(segs) == 1:
    ans = seglen(segs[0])
elif len(segs) == 2:
    if segs[1][0] == segs[0][1] + 1:
        ans = seglen(segs[0]) + seglen(segs[1])
    else:
        ans = max([seglen(x) for x in segs])
else:
    ans = max([seglen(x) for x in segs])
    for i in range(len(segs)-1):
        if segs[i][1] + 1 == segs[i+1][0]:
            ans = max(ans, seglen(segs[i]) + seglen(segs[i+1]) + 1)

print(ans)
