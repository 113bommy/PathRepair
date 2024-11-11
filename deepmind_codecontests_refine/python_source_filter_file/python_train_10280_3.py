import fractions

def extendedEuclid(A, B):
	X = 0; Y = 0
	if B == 0:
		X = 1; Y = 0
	else:
		X, Y = extendedEuclid(B, A % B)
		temp = X
		X = Y; Y = temp - (A // B) * Y
	return X, Y

def DiophantusSolver(a, b, c):
	g = abs(fractions.gcd(a, b))
	if c % g != 0: return (10 ** 40, 10 ** 40)
	p, q = extendedEuclid(abs(a // g), abs(b // g))
	r11 = (p * c // g); r12 = (q * c // g)
	t1 = xi + r11 * n
	q, p = extendedEuclid(abs(b // g), abs(a // g))
	r21 = (p * c // g); r22 = (q * c // g)
	t2 = xi + r21 * n
	if (r11, r12) < (r21, r22): return r11, r12
	return r21, r22

n, m, x, y, vx, vy = map(int, input().split())

if vx * vy == 0:
	if vx == 0:
		if x > 0 and x < n: print('-1')
		elif vy < 0: print('{} 0'.format(x))
		elif vy > 0: print('{} {}'.format(x, m))
	elif vy == 0:
		if y > 0 and y < m: print('-1')
		elif vx < 0: print('0 {}'.format(y))
		elif vx > 0: print('{} {}'.format(n, y))
else:
	xi = x % n; yi = y % m
	LCM = (n * m // fractions.gcd(n, m))
	if vx > 0: xi = (n - x) % n
	if vy > 0: yi = (m - y) % m
	tx, ty = DiophantusSolver(n, -m, yi - xi)
	if (tx == 10 ** 40):
		print('-1')
	else:
		t = xi + tx * n
		while t < 0: t += LCM
		x1 = (x + t * vx) % (n * 2)
		while x1 < 0: x1 += (n * 2)
		y1 = (y + t * vy) % (m * 2)
		while y1 < 0: y1 += (m * 2)
		print(x1, y1)