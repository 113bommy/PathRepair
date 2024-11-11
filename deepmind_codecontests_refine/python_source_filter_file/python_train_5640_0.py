from queue import PriorityQueue
from queue import Queue
import math
from collections import defaultdict
import sys
import operator as op
from functools import reduce

i = lambda: list(map(int,sys.stdin.readline().split()))

n, = i()
arr= [0] * n
for _ in range(n-1):
	u, v = i()
	arr[u-1] += 1
	arr[v-1] += 1
fl = 0
for k in arr:
	if k % 2 == 0:
		fl = 1
		break
if fl == 0:
	print("YES")
else:
	print("NO")

