from itertools import permutations

d, g = map(int, input().split())
g = g // 100
p = []
c = []

for _ in range(d):
	pp, cc = map(int, input().split())
	p.append(pp)
	c.append(cc // 100)

ans = float("inf")
for array in permutations(range(d)):
	gap = g
	num = 0
	for a in array:
		if p[a] * (a + 1) >= gap:
			num += (gap - 1) // (a + 1) + 1
			break
		elif p[a] * (a + 1) + c[a] >= gap:
			num += p[a]
			break
		else:
			num += p[a]
			gap -= p[a] * (a + 1) + c[a]

	if num < ans:
		ans = num

print(ans)