'''input
54321 12345
'''
from sys import stdin
input = stdin.readline
import math
import sys
from collections import defaultdict
sys.setrecursionlimit(10 ** 4)



def lowbit(n):
	return n - (n &(n - 1))
	
# main starts
s, limit = list(map(int, input().split()))
k = math.ceil(math.log(limit, 2))
ans = set()
for i in range(limit, 1, -1):
	x = lowbit(i)
	if s >= x:
		s -= x
		ans.add(i)
if s > 0:
	print(-1)

else:
	print(len(ans))
	for i in ans:
		print(i, end = ' ')