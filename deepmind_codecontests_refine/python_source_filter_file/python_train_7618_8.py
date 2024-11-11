import math, sys
from collections import defaultdict, Counter, deque
 
INF = float('inf')
MOD = int(1e9) + 7
 
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

def main():
	n, m = vars()

	mat = []

	for i in range(n):
		mat.append(array())

	ans = 0 

	for i in range(n):
		for j in range(m):
			if mat[i][j]:
				if i > 0 and mat[i][j] < mat[i - 1][j]:
					print(-1)
					return 
				if j > 0 and mat[i][j] < mat[i][j - 1]:
					print(-1)
					return
	
	for i in range(n - 1, -1, -1):
		for j in range(m - 1, -1, -1):
			if mat[i][j] == 0:
				num = min(mat[i][j + 1], mat[i + 1][j]) - 1
				if num > mat[i - 1][j] and num > mat[i][j - 1]:
					mat[i][j] = num 
				else:
					print(-1)
					return 
			ans += mat[i][j]


	print(ans)	
	return


if __name__ == "__main__":
	t = 1
	# t = int(input())
	for _ in range(t):
		main()
