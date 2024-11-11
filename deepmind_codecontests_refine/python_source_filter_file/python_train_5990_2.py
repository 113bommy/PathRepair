from collections import defaultdict
n, q = map(int, input().split())
es = defaultdict(list)
for _ in range(q):
	a, b = input().split()
	es[b].append(a)

ss = set('a')
for i in range(n):
	ssp = set()
	for s in ss:
		for e in es[s[0]]:
			ssp.add(e + s[1:])
	ss = ssp
	if not ss:
		break
print(len(ss))
