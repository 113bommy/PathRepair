import bisect
import copy
import decimal
import fractions
import heapq
import itertools
import math
import random
import sys
from collections import Counter, deque,defaultdict
from functools import lru_cache,reduce
from heapq import heappush,heappop,heapify,heappushpop,_heappop_max,_heapify_max
def _heappush_max(heap,item):
    heap.append(item)
    heapq._siftdown_max(heap, 0, len(heap)-1)
def _heappushpop_max(heap, item):
    if heap and item < heap[0]:
        item, heap[0] = heap[0], item
        heapq._siftup_max(heap, 0)
    return item
from math import gcd as GCD
read=sys.stdin.read
readline=sys.stdin.readline
readlines=sys.stdin.readlines

N=int(readline())
S=0
dct=defaultdict(int)
for _ in range(N):
    a,b=map(int,readline().split())
    dct[b]+=a
    S+=a
ans=0
cnt=0
for b in sorted(dct.keys()):
    ans=max(ans,min(S+b-cnt,2*S))
    cnt+=dct[b]
print(ans)