t = int(input())

for _ in range(t):
	a, b, c, m = map(int, input().strip().split())

	a, b, c = sorted([a,b,c]) # a <= b <= c

	if m > 0:
		todel = min(c - b, m)
		m -= todel
		c -= todel

	if m > 0:
		todel = min((b - a) * 2, m)
		todel2 = todel // 2
		m -= todel2 * 2
		c -= todel2
		b -= todel2

	if m > 0:
		todel = min((a - 1) * 3, m)
		todel3 = todel // 3
		m -= todel3 * 3
		c -= todel3
		b -= todel3
		a -= todel3
	
	ok = True

	if m > 0:
		ok = sum([a, b, c]) - 3 >= m
	else:
		ok = a + b >= c

	print("YES" if ok else "NO")
