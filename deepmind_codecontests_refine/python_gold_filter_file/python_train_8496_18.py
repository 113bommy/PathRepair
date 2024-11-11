from math import ceil
n = int(input().strip())
days = 0
for i in range(n):
	a, b = map(int, input().strip().split())
	days += 1
	x = max(0, ceil((days-a)/b))
	days = a + b*x
print(days)