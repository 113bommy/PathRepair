import bisect
import collections
import copy
import functools
import heapq
import itertools
import math
import random
import re
import sys
import time
import string
from typing import *
sys.setrecursionlimit(99999)

mod = 10**9 + 7
h, w = map(int, input().split())
ah = list(map(int, input().split()))
ac = list(map(int, input().split()))

dp = [[0] * w for _ in range(h)]

for i, c in enumerate(ah):
    for j in range(c):
        dp[i][j] = 1

for j, c in enumerate(ac):
    for i in range(c):
        dp[i][j] = 1

b = True
for i in range(h):
    j = 0
    while j < w and dp[i][j] == 1:
        j += 1
    if j + 1 != ah[i]:
        b = False
        break
if not b:
    print(0)
else:
    for j in range(w):
        i = 0
        while i < h and dp[i][j] == 1:
            i += 1
        if i + 1 != ac[j]:
            b = False
            break
    if not b:
        print(0)
    else:

        k = 0
        for i in range(1, h):
            for j in range(1, w):
                if dp[i][j] == 0 and i > ac[j] and j > ah[i]:
                    k += 1
        print(pow(2, k, mod))
