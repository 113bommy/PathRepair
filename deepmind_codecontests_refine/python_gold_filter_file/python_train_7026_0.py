II = lambda: map(int,input().split())
n,m = II()
from collections import defaultdict
edges = defaultdict(set)
for _ in range(m):
	a,b = II()
	edges[a].add(b)
	edges[b].add(a)
ans = 99999999
for v in edges.values():
	for second in v:
		for third in v:
			if third in edges[second]:
				reg = len(edges[third]) + len(edges[second]) + len(v) - 6
				if reg >= 0:
					ans = min(ans, reg)
print(ans if ans != 99999999 else -1)