def GCD(a, b):
	while (a != 0 and b != 0):
		a, b = b % a, a
	return max(a, b)
a, b, x, y = map(int, input().split())
f = GCD(x, y)
x //= f
n = min(a, b * x // y)
print(n // x)