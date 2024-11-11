import math

n = int(input())

if n in [1,2,3]:
	print("1")
else:
	smallestDivisor = n
	if n % 2 == 0:
		smallestDivisor = 2
	elif n % 3 == 0:
		smallestDivisor = 3
	else:
		for i in range(5, int(math.sqrt(n)) + 1, 2):
			if n % i == 0:
				smallestDivisor = i
				break

	while n % smallestDivisor == 0:
		n //= smallestDivisor

	print(str(smallestDivisor) if n == 1 else "1")
