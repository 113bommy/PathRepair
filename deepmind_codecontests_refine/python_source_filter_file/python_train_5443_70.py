from __future__ import print_function # for PyPy2
from collections import Counter, OrderedDict
from itertools import permutations as perm
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
import math
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

t, = gil()
for _ in range(t):
	l, r = gil()
	print("YES" if 2*(r-l) <= l else "NO")