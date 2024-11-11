n = int(input())
a = list(map(int, input().split()))
if a.count(0) == n:
	print('NO')
else:
	if sum(a) != 0:
		print('YES')
		print(1)
		print(1, n)
	else:
		i = 0
		while sum(a[:i]) == 0:
			i += 1
		print('YES')
		print(2)
		print(1, i + 1)
		print(i + 2, n)
