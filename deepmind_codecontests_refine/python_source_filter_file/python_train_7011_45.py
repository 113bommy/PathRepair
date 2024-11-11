# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys

"""
created by shhuan at 2017/11/24 13:41

"""

N, M = map(int, input().split())

ans = 0
for a in range(N//2+1):
    for b in range(M//2+1):
        if a*a+b == N and a+b*b == M:
            ans += 1

print(ans)