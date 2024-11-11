x, y, z, t1, t2, t3 = map(int, input().split())

lift = t3 + abs(z - x) * t2 + 2*t3 + abs(x - y) * t2 + t3
masha = t1 * abs(x - y)

if (lift > masha):
	print('NO')
else:
	print('YES')