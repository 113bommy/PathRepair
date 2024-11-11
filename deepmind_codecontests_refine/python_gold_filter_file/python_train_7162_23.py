import sys, math
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from itertools import combinations, permutations, product
from heapq import heappush, heappop
from functools import lru_cache
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 1000000007
sys.setrecursionlimit(1000000)

N = ri()
to = defaultdict(list)
V = 100005
X = []
for i in range(N):
	x, y = rl()
	X.append(x)
	y += V
	to[x].append(y)
	to[y].append(x)

visited = set()
nx, ny = 0, 0
def dfs(n):
	global nx, ny
	if n in visited: return
	visited.add(n)
	if n < V:
		nx += 1
	else:
		ny += 1
	for m in to[n]:
		dfs(m)

ans = 0
for x in X:
	if x in visited: continue
	nx, ny = 0, 0
	dfs(x)
	ans += nx*ny
print(ans-N)

