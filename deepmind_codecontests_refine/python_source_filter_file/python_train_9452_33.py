import sys
sys.setrecursionlimit(1000000000000)

def dfs(i):
	if i in use:
		return 
	use.add(i)
	for e in edges_r[i]:
		dfs(e)

def bf():
	d = [float('inf') for _ in range(n + 1)]
	d[1] = 0
	for _ in range(n):
		f = False
		for e in edges_f:
			if d[e[1]] > d[e[0]] + e[2]:
				d[e[1]] = d[e[0]] + e[2]
				f = True	
		if not f:
			return max(0, -1 * d[n])
	return -1

n, m, p = list(map(int, input().split()))

edges_f = []
edges_r = [[] for i in range(n + 1)]
for _ in range(m):
	a, b, c = list(map(int, input().split()))
	edges_f.append([a, b, -1 * (c - p)])
	edges_r[b].append(a)

use = set()
dfs(n)

edges_f = [e for e in edges_f if e[0] in use and e[1] in use]
print(bf())