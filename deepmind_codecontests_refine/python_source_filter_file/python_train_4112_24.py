n = int(input())
sum = 0
exponent = len(str(n)) - 1
while n > 9:
	m = (n % 10**exponent) + 1
	sum += (exponent + 1)*m
	n -= m
	exponent -= 1
sum += n
print(sum)