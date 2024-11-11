def solve(n, m, white, black):
	w, b = tiles(1, 1, m, n)
	_, b2w = tiles(*white)
	w2b, _ = tiles(*black)

	w += b2w
	b -= b2w
	w -= w2b
	b += w2b

	x1, y1 , x2, y2 = max(white[0], black[0]), max(white[1], black[1]), min(white[2], black[2]), min(white[3], black[3])

	if (x1 <= x2 and y2 <= y1):
		_, b2 = tiles(x1, y1, x2, y2)
		w -= b2
		b += b2 

	return w, b

def tiles(x1, y1, x2, y2):
	n = y2 - y1 + 1
	m = x2 - x1 + 1
	black = (x1 + y1) % 2
	w = (n//2) * m  + (m+(not black))//2 * (n%2)
	b = (n//2) * m  + (m+(black))//2 * (n%2)
	return w, b

def read(): return list(map(int, input().split()))

q = int(input())
for _ in range(q):
	print(*solve(*read(), read(), read()), sep=' ')
