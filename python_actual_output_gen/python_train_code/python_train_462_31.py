a, b, c = map(int, input().split())

if a == b or (c != 0 and (b - a) % c == 0 and b * c > 0):
	print('YES')
else:
	print('NO')
