n, a, b = map(int, input().split())
a, b = a - 1, b - 1
count = 1
while a // 2 != b // 2:
	count += 1
	a //= 2
	b //= 2
if 2 ** count == n:
	print("Final")
else:
	print(count)
