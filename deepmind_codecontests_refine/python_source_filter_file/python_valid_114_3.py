import sys
from math import factorial, gcd
#from math import comb, perm 	
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right 
from heapq import heappop, heappush, heapify, nlargest, nsmallest
from itertools import groupby
from copy import deepcopy
MOD = 10**9+7
INF = float('inf')

rl = lambda : list(map(int, sys.stdin.readline().split()))
rs = lambda : sys.stdin.readline().strip()


n = int(input())
items = [rl() for _ in range(n)]
m = int(input())
banned = set([tuple(rl()) for _ in range(m)])
heap = [(-sum(a[-1] for a in items), tuple(len(a) - 1 for a in items))]
seen = set()
while heap:
	val, tp = heappop(heap)
	if tp not in banned:
		print(*tp)
		break

	for i in range(n):
		if tp[i] > 2:
			l = list(tp)
			l[i] -= 1
			l = tuple(l)
			if l not in seen:
				seen.add(l)
				newVal = val - items[i][l[i]] + items[i][tp[i]]
				heappush(heap, (newVal, l))