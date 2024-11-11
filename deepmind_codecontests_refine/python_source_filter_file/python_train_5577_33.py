n, a, b, c = map(int, input().split())

left = n % 4

if left == 4:
	print(0)
elif left == 3:
	print(a, b + c, 3*c)
elif left == 2:
	print(min(2*a, b, 2*c))
else:
	print(min(3*a, a + b, c))