# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 3/8/18

"""

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys

a, b = map(int, input().split())

while a > 0 and b > 0:
    if a > 2*b:
        t = a // b // 2
        t *= 2
        a -= t * b
    elif b > 2*a:
        t = b // a // 2
        t *= 2
        b -= t * a
    else:
        break
print(a, b)