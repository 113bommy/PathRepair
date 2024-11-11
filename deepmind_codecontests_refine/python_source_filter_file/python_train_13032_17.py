x, n = [int(x) for x in input().split()]

from math import sqrt, ceil, log

primes = [0]*(10**4*6)

for i in range(2, len(primes)):
	if primes[i] == 0:
		primes[i] = i
		for j in range(2*i, len(primes), i):
			primes[j] = -1

Primes = []
for prime in primes:
	if prime >= 2:
		Primes.append(prime)

primes = Primes

def containspower(base, num):
	l, r = 0, int(log(num, base)+1)
	while r-l > 1:
		c = (l + r) // 2
		if num % (base**c) == 0:
			l = c
		else:
			r = c
	return l

def factor(x):
	ans = []
	for i in primes:
		if x % i == 0:
			ans.append((i, containspower(i, x)) )
			x //= i**ans[-1][1]
	if x != 1:
		ans.append((x, 1))
	return ans


xx = factor(x)
# print(xx)

ans = 1
for p, power in xx:
	pa = 1
	for i in range(1, int(log(n, p))+1):
		a = pow(p, (n // p**i), 10**9+7)
		# print(f"{a = } {p = } {i = }")
		pa *= a if a != 0 else 1
	ans *= pa
	ans %= 10**9+7

print(ans % (10**9+7))
