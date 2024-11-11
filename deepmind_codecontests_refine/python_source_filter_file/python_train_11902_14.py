import math, sys
from collections import defaultdict, Counter, deque 
from heapq import heapify, heappush, heappop

MOD = int(1e9) + 7
INF = float('inf')


def solve():
	n, x, t = map(int, input().split())

	f = min(t // x, n - 1)

	if not f:
		print(0)
		return

	if f == n - 1:
		ans = f * (f + 1) // 2
	else:
		ans = f * (n - f) - 1
		ans += f * (f + 1) // 2

	print(ans)
	


def main():
	ts = 1
	ts = int(input())
	for t in range(1, ts + 1):
		solve()






def input():
	return sys.stdin.readline().rstrip('\n').strip()

def print(*args, sep=' ', end='\n'):
	first = True
	for arg in args:
		if not first:
			sys.stdout.write(sep)
		sys.stdout.write(str(arg))
		first = False 

	sys.stdout.write(end)

def flush():
	sys.stdout.flush()


main()


