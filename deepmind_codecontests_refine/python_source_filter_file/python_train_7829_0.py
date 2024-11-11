a = []
for _ in range(3):
	a.append(input())
if a[0][0] == a[2][2] and a[0][1] == a[2][1] and a[2][0] == a[2][0] and a[1][2] == a[1][0]:
	print('YES')
else:
	print('NO')