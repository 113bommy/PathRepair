n = int(input())
f = [0] * (n + 1)
p = [(0, 0, 0)] * (n + 1)
for i in range(1, n + 1):
	x, y = map(int, input().split())
	p[i] = (x, y, max(x, y))

p.sort(key=lambda x : (x[2], x[0] - x[1]))

def dis(a, b):
	return abs(a[0] - b[0]) + abs(a[1] - b[1])

lasi = lasj = 0
i = 1
while i <= n:
	j = i
	while j < n and p[j + 1][2] == p[i][2]:
		j += 1
	for k in {i, j}:
		f[k] = dis(p[i], p[j]) + min(f[l] + dis(p[l], p[k]) for l in {lasi, lasj})
	lasi, lasj = i, j
	i = j + 1

print(min(f[lasi], f[lasj]))