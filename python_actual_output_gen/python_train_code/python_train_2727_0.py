x, y, n = map(int, input().split())
best, mn, eps = [0, 0], 10**9, 1e-15
for i in range(1, n+1):
	m1 = (i*x) // y
	m2 = (i*x+y-1) / y
	a = abs(x/y - m1/i)
	b = abs(x/y - m2/i)
	if a < mn - eps:
		mn = a
		best = [m1, i]
	if b < mn - eps:
		mn = b
		best = [m2, i]
print(*best, sep='/')
