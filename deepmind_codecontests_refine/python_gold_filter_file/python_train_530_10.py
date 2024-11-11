for i in range(int(input())):
	m, n = map(int, input().split())
	s0 = s1 = n * m // 2
	if n * m % 2 == 1:
		s0 += 1
	x1, y1, x2, y2 = map(int, input().split())
	x3, y3, x4, y4 = map(int, input().split())
	d1, d2 = x4 - x3 + 1, y4 - y3 + 1
	if d1 * d2 % 2 == 1 and (x3 + y3) % 2 == 0: 
		s0 -= d1 * d2 // 2 + 1
		s1 += d1 * d2 // 2 + 1
	else:
		s0 -= d1 * d2 // 2
		s1 += d1 * d2 // 2
	a = []
	a.append([1, 1, x3 - 1, y3 - 1])
	a.append([1, y3, x3 - 1, y4])
	a.append([1, y4 + 1, x3 - 1, m])
	a.append([x3, 1, x4, y3 - 1])
	a.append([x3, y4 + 1, x4, m])
	a.append([x4 + 1, 1, n, y3 - 1])
	a.append([x4 + 1, y3, n, y4])
	a.append([x4 + 1, y4 + 1, n, m])
	for b in a:
		nx1, ny1, nx2, ny2 = max(b[0], x1), max(b[1], y1), min(b[2], x2), min(b[3],y2)
		if nx1 > nx2 or ny1 > ny2: continue
		d1, d2 = nx2 - nx1 + 1, ny2 - ny1 + 1
		if d1 * d2 % 2 == 1 and (nx1 + ny1) % 2 == 1: 
			s0 += d1 * d2 // 2 + 1
			s1 -= d1 * d2 // 2 + 1
		else:
			s0 += d1 * d2 // 2
			s1 -= d1 * d2 // 2
	print(s0, s1)