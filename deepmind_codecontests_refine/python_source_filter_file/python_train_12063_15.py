import math

while True:
	try:
		a, b = map(int, input().split())
		print(int(math.log(a + b, 10)) + 1)
	except EOFError:
		break