from collections import Counter, defaultdict, OrderedDict, deque
from bisect import bisect_left, bisect_right
from functools import reduce, lru_cache
from typing import List
import itertools
import sys
import math
import heapq
import string
import random
MIN, MAX, MOD = -0x3f3f3f3f, 0x3f3f3f3f, 1000000007
def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
n = N()
if n == 20: print(15)
elif n <= 10 or n >= 21: print(0)
else: print(4)