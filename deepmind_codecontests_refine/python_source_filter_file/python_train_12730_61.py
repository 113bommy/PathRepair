n = int(input())

for _ in range(n):
	m = int(input())

	print(*[m + i*m for i in range(m)])