def getP(b):
	d = 2
	a = []
	while d * d <= b:
		if b % d == 0:
			p = d
			deg = 0
			while b % d == 0:
				b //= d
				deg += 1
			a.append((p, deg))
		d += 1
	if b != 1:
		a.append((b, 1))
	return a


n, b = map(int, input().split())

a = getP(b)

ans = 100

for p, deg in a:
	cur = p
	res = 0
	while cur <= n:
		res += n // cur
		cur *= p
	ans = min(ans, res // deg)

print(ans)