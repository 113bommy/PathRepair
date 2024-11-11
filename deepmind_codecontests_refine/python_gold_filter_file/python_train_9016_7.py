# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random

"""
created by shhuan at 2017/10/8 09:18
    
"""


N, K, M = map(int, input().split())

nums = [int(x) for x in input().split()]

nums = [(x%M, x) for x in nums]

sv = collections.defaultdict(list)
for r, v in nums:
    sv[r].append(v)
    if len(sv[r]) == K:
        print('Yes')
        print(' '.join(map(str, sv[r])))
        exit(0)

print('No')




