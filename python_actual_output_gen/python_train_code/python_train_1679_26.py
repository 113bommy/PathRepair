n = int(input())
maximum = 1
k = 1
while (2 **(k - 1)) * ((2 ** k) - 1) < n:
	if n % (2 **(k - 1)) * ((2 ** k) - 1) == 0:
		maximum = (2 **(k - 1)) * ((2 ** k) - 1)
	k += 1
print(maximum)		