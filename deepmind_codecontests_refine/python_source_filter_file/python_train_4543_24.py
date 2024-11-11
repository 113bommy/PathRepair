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
created by shhuan at 2017/11/19 21:52

"""

MOD = 1000000007

N, M, K = map(int, input().split())


def my_pow_2(x):
    if x == 0:
        return 1

    h = my_pow_2(x//2)
    if x & 1:
        return (h*h*2) % MOD
    else:
        return (h*h) % MOD

if K == -1 and N%2 != M%2:
    print(-1)
else:
    print(my_pow_2((N-1)*(M-1)))

