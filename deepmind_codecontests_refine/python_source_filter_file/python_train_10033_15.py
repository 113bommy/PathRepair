import random, math
from copy import deepcopy as dc

# To Genrate Random Number for Test-Cases
def randomNumber(s, e):
	return random.randint(s, e)

# To Generate Random Array for Test-Cases
def randomArray(s, e, s_size, e_size):
	size = random.randint(s_size, e_size)
	arr = [randomNumber(s, e) for i in range(size)]
	return arr

# To Generate Question Specific Test-Cases
def testcase():
	pass

# Brute Force Approach to check Solution
def brute():
	pass

# Efficient Approach for problem
def effe():
	pass


# Seive of Eratosthenes
MAXN = 3001
primes = [1] * MAXN
primes[0] = 0
primes[1] = 0
def seive():
	i = 2
	while i*i <= MAXN:
		if primes[i]:
			for j in range(i*i, MAXN+1, i):
				primes[j] = 0
		i += 1

def checkAlmost(n):
	c = 0
	for i in range(1, n+1):
		if primes[i] and n % i ==0:
			c += 1
	if c >= 2:
		return True
	return False


# Function to call the actual solution
def solution(n):
	c = 0
	for i in range(1, n+1):
		if checkAlmost(i):
			c += 1
	return c
	


# Function to take input
def input_test():
	n = int(input())
	out = solution(n)
	print(out)

# Function to check test my code
def test():
	pass

seive()
input_test()
# test()