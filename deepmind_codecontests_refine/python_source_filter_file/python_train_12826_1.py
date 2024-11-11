# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys
from typing import List

"""
created by shhuan at 2019/12/30 21:12

"""


N, K = map(int, input().split())

wc = collections.defaultdict(int)
for x in itertools.combinations([i for i in range(1, K+2)], K):
    print('? {}'.format(' '.join(map(str, x))))
    sys.stdout.flush()
    i, v = map(int, input().split())
    wc[v] += 1

print('! {}'.format(K+1-min(wc.values())))

