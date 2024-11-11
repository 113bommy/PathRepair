from math import gcd
from sys import stdout
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
print = stdout.write

primes = []
n = 10**5+1
mark = [True]*(n)
for i in range(2,n):
	if mark[i]:
		primes.append(i)
		for j in range(i, n, i): mark[i] = False

del mark

for _ in range(int(input())):	
	a, m = map(int, input().split())
	m //= gcd(a, m)
	ans = m
	for i in primes:
		if m==1: break
		if m%i == 0:
			ans -= ans//i
			while m%i == 0: m //= i
	else: ans -= ans//m
	print(str(ans))