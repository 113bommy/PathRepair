import copy
import itertools
import string
import sys

###

def powmod(x, p, m):
	if p <= 0:
		return 1
	if p <= 1:
		return x%m
	return powmod(x*x%m, p//2, m) * (x%m)**(p%2) % m

###

def to_basex(num, x):
	while num > 0:
		yield num % x
		num //= x

def from_basex(it, x):
	ret = 0
	p = 1
	for d in it:
		ret += d*p
		p *= x
	return ret

###

def l4(x):
	ret = 1
	while x > 4:
		ret += 1
		x //= 4
	return ret


def core():
	n = int(input())
	# print(n)
	ans = 0
	for _ in range(n):
		k, a = (int(x) for x in input().split())
		# print(k, a)
		
		ans = max(ans, l4(a) + k)
	print(ans)


core()















































