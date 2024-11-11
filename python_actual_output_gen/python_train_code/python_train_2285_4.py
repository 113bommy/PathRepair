import sys

def gcd(a, b):
	if b < 10e-4:
		return a
	return gcd(b, a % b)

a, b, c, d = [int(i) for i in sys.stdin.readline().split()]

x = a / c
y = b / d

f = max(x if x * d <= b else -1, y if y * c <= a else -1)

common = gcd(f * f * c * d, a * b)
down = a * b // common
up = down - (f * f * c * d // common)

print("{}/{}".format(int(up), int(down)))
