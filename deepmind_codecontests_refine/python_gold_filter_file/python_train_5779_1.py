def isPrime(n):
	i = 2
	while (i * i < n + 1):
		if n % i == 0:
			return False
		i += 1
	return True

n = int(input())

if isPrime(n) :
	print("1")
	print(n)
elif isPrime(n - 2) :
	print("2\n2 " + str(n - 2))
else :
	temp = n
	while (not isPrime(temp)) or n - temp < 4 :
		temp -= 1
	n -= temp
	for i in range(2, n + 2) :
		if isPrime(i) and isPrime(n - i) :
			print("3\n" + str(n - i) + " " + str(i) + " " + str(temp))
			break