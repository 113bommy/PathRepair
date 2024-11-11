
n = int(input())
l = [0 for _ in range(n)]

pos = 0
for i in range(2 * n + 1):
	pos += i
	if pos >= n:
		pos %= n
	l[pos] = 1

if len(set(l)) == 2:
	print('NO')
else:
	print('YES')


