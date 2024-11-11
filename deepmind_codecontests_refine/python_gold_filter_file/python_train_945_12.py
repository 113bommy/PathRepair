from math import gcd
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
x = 0
for _ in range(int(input())):
	a, b = map(int, input().split())
	x = gcd(x,a*b)
if x == 1: print(-1)
else:
	if gcd(x,a) != 1: x = gcd(x,a)
	else:  x = gcd(x,b)
	n = int(x**(.5))
	mark = [False]*(n+1)
	mark[0] = mark[1] = True
	primes = set()
	for i in range(2,n+1):
		if mark[i] == False:
			if x%i == 0: 
				print(i)
				break
			primes.add(i)
			for j in range(i+i, n+1, i):
				mark[j] = True
	else: print(x)	