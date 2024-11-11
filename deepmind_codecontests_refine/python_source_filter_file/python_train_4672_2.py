def Cramer(a11, a12, a13, a21, a22, a23):
	den = a11 * a22 - a12 * a21
	return (a13 * a22 - a12 * a23) / den, (a11 * a23 - a13 * a21) / den

while True:
	try:
		x1, y1, x2, y2, x3, y3, xp, yp = [eval(item) for item in input().split()]
		u, v = Cramer(x3 - x1, x2 - x1, xp - x1, y3 - y1, y2 - y1, yp - y1)
		print('YES' if u >= 0.0 and v >= 0.0 and u + v - 1.0 < 1e10 else 'NO')
	except EOFError:
		break