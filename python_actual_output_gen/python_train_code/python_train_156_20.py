for _ in range(int(input())):
	n = int(input())
	*a, = map(int, input().split())
	if len(set(i + a[i] for i in range(n))) == n:
		print('YES')
	else:
		print('NO')