import itertools

while True:
	n, m, a = map(int, input().split())
	if (n,m,a) == (0,0,0):
		break
	hpq = [list(map(int, input().split())) for i in range(m)]
	hpq = sorted(hpq, reverse=True)
	for k, g in itertools.groupby(hpq, key=lambda x:x[0]):
		for gg in g:
			if a == gg[1]:
				a = gg[2]
				break
			elif a == gg[2]:
				a = gg[1]
				break
	print(a)