n = int(input())

x = (n // 10) * 10

if n - x > 5:
	print(int(x + 10))
else:
	print(int(x))