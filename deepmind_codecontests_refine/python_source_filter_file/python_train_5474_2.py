def gcd(a, b):
	if a == 0:
		return [b, 0, 1]
	d, x1, y1 = gcd (b % a, a)
	return [d, y1 - (b // a) * x1, x1]
def find_any_solution(a, b, c):
	g, x0, y0 = gcd(abs(a), abs(b))
	if c % g != 0:
		return [False, 0, 0, 0]
	x0 *= c // g
	y0 *= c // g
	if a < 0:
		x0 *= -1
	if b < 0:
		y0 *= -1
	return [True, x0, y0, g]
def main():
	x, y, p, q = [int(i) for i in input().split()]
	if p == 0 and x != 0:
		print(-1)
		return 0
	ok = find_any_solution(q, -p, p * y - x * q);
	if not ok[0]:
		print(-1)
		return;
	print(ok)
	a = ok[1]
	b = ok[2]
	g = ok[3]
	ag = q // g
	bg = (-p) // g; 
	print(a, b, ag, bg)
	if ag == -1 * bg and a > b:
		print(-1)
		return 0
	l, r = -10 ** 18, 10 ** 18
	while r - l > 1:
		m = (l + r) // 2;
		if a + m * bg >= 0:
			l = m
		else:
			r = m
	maxk = l
	l, r = -10 ** 18, 10 ** 18
	while r - l > 1:
		m = (l + r) // 2;
		if b - m * ag >= 0:
			l = m
		else:
			r = m
	maxk = min(maxk, l)
	l, r = -10 ** 18, 10 ** 18
	while r - l > 1:
		m = (l + r) // 2
		if a + m * bg <= b - m * ag:
			l = m
		else:
			r = m
	if ag != bg * -1:
		maxk = min(l, maxk)
	if b - maxk * ag + y == 0:
		--maxk
	if b - maxk * ag + y == 0:
		print(-1)
		return;
	print(maxk)
	print(b - maxk * ag)
t = int(input())
for i in range(t):
	main()