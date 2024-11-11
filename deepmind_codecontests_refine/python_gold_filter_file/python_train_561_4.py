n, m, k = map(int, input().split())
a = [0]*n
w = [0]*n
for i in range(n):
	a[i] = list(input())
	w[i] = [0]*m
for sx in range(n):
	if a[sx].count('.'):
		sy = a[sx].index('.')
		break

q = [0]*(n*m)
q[0] = (sx, sy)
w[sx][sy] = 1
ql = 0
qr = 1
while ql < qr:
	x, y = q[ql]
	#print(x,y)
	ql += 1
	for dx, dy in ((0,1), (0, -1), (1, 0), (-1, 0)):
		xx = x + dx
		yy = y + dy
		if xx >= 0 and xx < n \
		and yy >= 0 and yy < m \
		and a[xx][yy] == '.' \
		and w[xx][yy] == 0:
			w[xx][yy] = 1
			q[qr] = (xx, yy)
			qr += 1
for i in range(qr-1, qr-1-k, -1):
	x, y = q[i]
	a[x][y] = 'X'
for i in range(n):
	print(*a[i], sep='')
