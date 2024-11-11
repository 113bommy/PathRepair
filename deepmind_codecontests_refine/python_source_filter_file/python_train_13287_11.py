n, a, b = map(int, input().split())
maximum = 0
for x in range(1, n + 1):
	if (a // x) + (b // x) >= n:
		maximum = x
print(maximum)		
