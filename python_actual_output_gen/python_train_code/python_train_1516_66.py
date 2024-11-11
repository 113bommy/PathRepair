x, y, z, t1, t2, t3 = map(int, input().split())
tt = abs(x - y) * t1
tt1 = t3 * 2 + abs(x - y) * t2 + abs(x - z) * t2
if tt > tt1:
	print('YES')
else:
	print('NO')
