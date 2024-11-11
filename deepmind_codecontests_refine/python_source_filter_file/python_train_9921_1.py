import sys

def input():
	return sys.stdin.readline().strip()

def mint():
	return int(input())

def mints():
	return map(int, input().split())

for i in range(mint()):
	input()
	n, m = mints()
	n2 = n*2
	e = [[] for i in range(n)]
	eb = [[] for i in range(n)]
	for i in range(m):
		u, v = mints()
		e[u-1].append(v-1)
		eb[v-1].append(u-1)
	q = [0]
	d = [None]*n
	d[0] = 0
	i = 0
	while i < len(q):
		x = q[i]
		i += 1
		for v in e[x]:
			if d[v] is None:
				d[v] = d[x] + 1
				q.append(v)
	idx = [None]*n
	for i in range(n):
		idx[i] = (d[i], i)
	idx.sort()
	q = []
	i = 0
	was = [[None]*n for _ in range(2)]
	ans = [int(2e9)]*n
	for _, id in idx:
		dd = d[id]
		for s in range(2):
			if was[s][id] is None:
				was[s][id] = (-1,-1)
				q.append((id,s))
				ans[id] = min(ans[id],dd)
		while i < len(q):
			x, s = q[i]
			i += 1
			for v in eb[x]:
				if d[x] < d[v]:
					if was[s][v] is None:
						q.append((v,s))
						was[s][v] = (x, s)
						ans[v] = min(ans[v],dd)
				elif s == 1:
					if was[0][v] is None:
						q.append((v,0))
						was[0][v] = (x, s)
						ans[v] = min(ans[v],dd)
	print(' '.join(map(str,ans)))
