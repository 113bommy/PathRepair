import sys
from heapq import heappush, heappop
sys.setrecursionlimit(10**6)

n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n-1):
	a, b = map(int, input().split())
	adj[a-1].append(b-1)
	adj[b-1].append(a-1)
num = [0 for _ in range(n)]
c = list(map(int, input().split()))
h = []
for i in range(n):
	heappush(h, -c[i])

def dfs(x):
	global h
	for v in adj[x]:
		if num[v] != 0:
			continue
		num[v] = -heappop(h)
		dfs(v)
	return

num[0] = -heappop(h)
dfs(0)
print(sum(c) - max(c))
print(*num)