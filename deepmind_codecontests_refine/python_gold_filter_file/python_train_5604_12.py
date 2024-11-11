def isPrime(x):
	for i in range(2,min(x,236)):
		if x%i == 0:
			return False
	return True
n,a,p = int(input()),[],2
while n > 0:
	if isPrime(p):
		a.append(str(p))
		n -= 1
	p += 5
print(" ".join(a))
