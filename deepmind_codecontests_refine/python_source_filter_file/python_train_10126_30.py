import math, sys
from collections import defaultdict, Counter, deque
 
INF = float('inf')
MOD = 10 ** 9 + 7
 
def gcd(a, b):
	while b:
		a, b = b, a%b
	return a
 
def isPrime(n):
	if (n <= 1): 
		return False
	i = 2
	while i ** 2 <= n:
		if n % i == 0:
			return False
		i += 1
	return True
 
def primeFactors(n):
	factors = defaultdict(int)
	i = 2
	while i ** 2 <= n:
		while n % i == 0:
			factors[i] += 1
			n //= i 
		i += 1
	if n > 1:
		factors[n] += 1 
	return factors
 
def vars():
	return map(int, input().split())
 
def array():
	return list(map(int, input().split()))


def a():
	n = int(input())
	m = defaultdict(int)

	for i in range(n):
		s = input()
		for c in s:
			m[c] += 1 

	res = 'YES'
	for c in m:
		if m[c] % n != 0:
			res = 'NO'
			break
	print(res)

def b():
	n = int(input())
	arr = array()

	arr.sort()

	maxi = arr[-1]

	res1 = math.floor(maxi ** (1 / (n - 1)))
	res2 = math.ceil(maxi ** (1 / (n - 1)))

	ans1 = ans2 = 0

	for i in range(n):
		ans1 += abs(arr[i] - (res1 ** i))

	for i in range(n):
		ans2 += abs(arr[i] - (res2 ** i))

	print(min(ans1, ans2))

if __name__ == "__main__":
	t = 1
	# t = int(input())
	for _ in range(t):
		a()
