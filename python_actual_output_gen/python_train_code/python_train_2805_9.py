n, t = list(map(int, input().split()))
a = list(map(int, input().split()))

i = 0
while (i < t):
	i += a[i]
if (i-1 == t):
	print('YES')
else:
	print('NO')
