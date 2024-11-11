import sys
import math,bisect
sys.setrecursionlimit(10 ** 5)
from collections import defaultdict
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,OrderedDict
def I(): return int(sys.stdin.readline())
def neo(): return map(int, sys.stdin.readline().split())
def Neo(): return list(map(int, sys.stdin.readline().split()))
n,k = neo()
Ans = 3*n
if k != 1 and k != n:
    Ans += min(k-1,n-k)
print(Ans)
