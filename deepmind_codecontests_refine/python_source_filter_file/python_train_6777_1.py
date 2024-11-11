from sys import stdin 
from collections import Counter 
from math import sqrt, gcd

def is_prime(n):
	d = 2
	while d * d <= n:
		if n % d == 0:
			return False
		d += 1
	return n > 1

def prime_factorize(n):
	if n in (0, 1):
		return []
	fact = []
	while n > 1:
		i = 2
		while i <= n:
			if n % i == 0:
				break 
			i += 1

		# finding exponent 
		e = 1
		while n % i == 0:
			n //= i 
			e += 1 
		if e - 1 > 1:
			fact.append((i, e - 1))
			return fact 
		elif e - 1 == 1:
			fact.append((i, e - 1))
			fact.append((n, 1))
			return fact 


def f(n):
	if int(sqrt(n))**2 == n:
		if int(sqrt(int(sqrt(n))))**4 == n:
			return 4, int(sqrt(int(sqrt(n))))
		else:
			return 2, int(sqrt(n))
	elif int(n**(1/3))**3 == n:
		return 3, int(n**(1/3))
	else:
		return None, None

t = int(input())
pf = Counter()
a = []
for _ in range(t):
	n, = map(int, stdin.readline().split())
	a.append(n)

ans = 1
spec = Counter()
for i in range(t):
	other = a[:i] + a[i + 1:]
	e, p = f(a[i])
	if e == None:
		z = True
		for j in other:
			if gcd(j, a[i]) != 1 and j != a[i]:
				z = False
				k = gcd(j, a[i])
				pf[k] += 1
				pf[a[i]//k] += 1
				break 
		if z:
			spec[a[i]] += 1


	else:
		pf[p] += e 

for i in pf.values():
	ans = ((i + 1)*ans) % 998244353 
for i in spec.values():
	ans = ((i + 1)**2)*ans % 998244353
print (ans % 998244353 )


