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
created by shhuan at 2017/11/24 22:32

"""

a, b, c = map(int, input().split())

# a + i*c == b

if c == 0:
    if a == b:
        print("YES")
    else:
        print("NO")
else:
    if c > 0 and a >= b:
        print("NO")
        exit(0)

    if c < 0 and a <= b:
        print("NO")
        exit(0)

    if (b-a) % c == 0:
        print("YES")
    else:
        print("NO")