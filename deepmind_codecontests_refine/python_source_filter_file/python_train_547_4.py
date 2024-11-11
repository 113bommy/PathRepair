import sys
from math import ceil, factorial, gcd
#from math import comb, perm 	only in python3
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right 
from heapq import heappop, heappush, heapify
MOD = 10**9 + 7
INF = float('inf')

rl = lambda : list(map(int, sys.stdin.readline().split()))

for _ in range(int(input())):
	n, m = rl()
	nums = [rl() for _ in range(n)]
	for i in range(n):
		for j in range(m):
			if (nums[i][j] - i - j) % 2 == 0:
				nums[i][j] += 1
			print(*nums[i])