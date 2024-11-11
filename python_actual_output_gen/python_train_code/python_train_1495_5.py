import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
from queue import PriorityQueue as pq
n,k=map(int,input().split())
if k>=n*(n+1)//2:
    print("no solution")
else:
    for i in range(n):
        print(i,0)