from sys import stdin,stdout
from collections import Counter
from collections import defaultdict
from math import ceil
from bisect import bisect_left 
from bisect import bisect_right
import math

ai = lambda: list(map(int, stdin.readline().split()))
ei = lambda: map(int, stdin.readline().split())
ip = lambda: int(stdin.readline().strip())


def isPrime(x): 
	if(x == 0 or x == 1) : 
		return 0
	i = 2
	while i * i <= x : 
		if (x % i == 0) : 
			return 0
		i = i + 1
	return 1

def findPrimes(n,ans) : 
	if (isPrime(n)): 
		ans += 1
	elif (isPrime(n - 2)) : 
		ans += 2 
	else: 
		ans += 1
		n = n - 3
		i = 0
		while i < n : 
			if (isPrime(i) and isPrime(n - i)) : 
				ans += 2
				break
			i = i + 1
	return ans

n = ip()
ans = 0
ans = findPrimes(n,ans)
print(ans)