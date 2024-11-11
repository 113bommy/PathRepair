import math

n, X, D = map(int, input().split())

if D == 0:
	if X == 0:
		print(1)
	else:
		print(N + 1)
	exit()

Y = dict()

for i in range(n + 1):
	b = -2 * i * X
	r = (n - 1 + n - i) * i // 2
	l = (0 + i - 1) * i // 2
	off = b % (-2 * D)
	l += (b - off) // (-2 * D)
	r += (b - off) // (-2 * D)
	if off in Y:
		Y[off].append((l, r))
	else:
		Y[off] = [(l, r)]

def calc(u):
	pt = dict()
	for l, r in u:
		if l in pt:
			pt[l] += 1
		else:
			pt[l] = 1
		if r + 1 in pt:
			pt[r + 1] -= 1
		else:
			pt[r + 1] = -1
	cur, v = -10 ** 100, 0
	ans = 0
	for k in sorted(pt.keys()):
		if v:
			ans += k - cur
		v += pt[k]
		cur = k
	return ans

print(sum(map(calc, Y.values())))
