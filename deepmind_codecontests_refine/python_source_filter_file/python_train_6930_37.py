n = int(input())

from math import sqrt; from itertools import count, islice
from sys import exit

def isPrime(n):
    return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

if n%2 == 1:
	print(1)
	exit()
else:
	# pair
	m = 1.
	while isPrime(n*m+1.):
		m += 1.
	print(int(m))
	exit()

# for m in range(2, int(1e3)+1):
# 	if n%m == 1:
# 		print(m-1)
# 		exit()
