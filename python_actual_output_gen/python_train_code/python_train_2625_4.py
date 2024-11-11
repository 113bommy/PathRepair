def is_prime(x):
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

def primes():
	i = 2
	while True:
		if is_prime(i):
			yield i
		i += 1

import itertools

n = int(input())
guesses = []
for p in itertools.takewhile(lambda p: p < n, primes()):
	x = p
	while x <= n:
		guesses.append(x)
		x *= p
print(len(guesses))
print(' '.join(map(str, guesses)))
