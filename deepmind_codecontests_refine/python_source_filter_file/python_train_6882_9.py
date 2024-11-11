def main():
	n = int(input())
	print(solver(n))

def countOfDigits(n):
	count = 0
	while n > 0:
		n //= 10
		count += 1
	return count

def sumOfDigits(n):
	total = 0 
	while n > 0:
		total += n % 10
		n //= 10
	return total

def getlastDthDigit(n, d):
	return (n % (10**d)) // 10**(d-1)

def solver(n):
	digitSum = sumOfDigits(n)
	digitCount = countOfDigits(n)
	ninescount = digitCount - 1
	for i in range(1, digitCount):
		if getlastDthDigit(n, i) != 9:
			ninescount = i - 1
			break		
	# if n % 10 == 9:
	# 	rem = 9
	# else:
	# 	rem = 0
	return 10 * (digitCount - 1) + digitSum - digitCount + 1 - 9 * ninescount
	# if n < 10:
	# 	return n
	# total = 10 + (n % 10)
	# n //= 10
	# while n >= 10:
	# 	lastdigit = n % 10
	# 	total += (10 + lastdigit)
	# 	if lastdigit == 0:
	# 		total -= 1
	# 	# if lastdigit != 0:
	# 	# 	total += (10 + lastdigit)
	# 	# else:
	# 	# 	total += (9
	# 	n //= 10
	# #total -= 11
	# total += (n - 1)
	# return total

# print(solver(35))
# print(solver(10**10))
#print(solver(99))
print(solver(999))
#main()


