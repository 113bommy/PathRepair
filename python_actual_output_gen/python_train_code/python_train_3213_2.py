a, b = map(int, input().split())
x, y, z = map(int, input().split())

x = x * 2
z = z * 3

a = a - x - y
b = b - z - y

if a < 0 and b > 0:
	print(abs(a))
elif a > 0 and b < 0:
	print(abs(b))
elif a < 0 and b < 0:
	print(abs(a+b))
else:
	print(0)