import math
from decimal import Decimal
import heapq
import copy
import heapq
from collections import deque
from collections import defaultdict
MOD = 1000000007
def na():
	n = int(input())
	b = [int(x) for x in input().split()]
	return n,b
 
	
def nab():
	n = int(input())
	b = [int(x) for x in input().split()]
	c = [int(x) for x in input().split()]
	return n,b,c
 
		
def dv():
	n, m = map(int, input().split())
	return n,m
 
 
def da():
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	return n,m, a 
 
 
def dva():
	
	n, m = map(int, input().split())
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	return n,m,b
 
 
def eratosthenes(n): 
	sieve = list(range(n + 1))
	for i in sieve:
		if i > 1:
			for j in range(i + i, len(sieve), i):
				sieve[j] = 0
	return sorted(set(sieve))
 
 
def lol(lst,k):
	k=k%len(lst)
	ret=[0]*len(lst)
	for i in range(len(lst)):
		if i+k<len(lst) and i+k>=0:
			ret[i]=lst[i+k]
		if i+k>=len(lst):
			ret[i]=lst[i+k-len(lst)]
		if i+k<0:
			ret[i]=lst[i+k+len(lst)]
	return(ret)
def nm():
	n = int(input())
	b = [int(x) for x in input().split()]
	m = int(input())
	c = [int(x) for x in input().split()]
	return n,b,m,c
 
 
def dvs():
	n = int(input())
	m = int(input())
	return n, m 
 
 
def fact(n):
	tc = []
	ans = {}
	d = 2
	while d * d <= n:
		if n % d == 0:
			tc.append(d)
			n //= d
		else:
			d += 1
	if n > 1:
		tc.append(n)
	for i in tc:
		ans[i] = ans.get(i, 0) + 1
	return ans


def to_zero(n, s):
	lst = s[0]
	ans = []
	for i in range(n):
		if lst == s[i]:
			continue
		else:
			if lst == '0':
				lst = '1'
				ans.append(i)
			else:
				lst = '0'
				ans.append(i)
	if lst == '1':
		ans.append(n)
	return ans


n, m, sx, sy = map(int, input().split())
print(sx, sy)
if sy != m:
	for i in range(1, m + 1):
		if i != sy:
			print(sx, i)
	x = 1
	y = m
	while x <= n:
		if x == sx:
			x += 1
			continue
		if y == m:
			for i in range(m, 0, -1):
				print(x, i)
				y = i
		else:
			for i in range(1, m + 1):
				print(x, y)
				y = i
		x += 1
else:
	for i in range(m, 0, - 1):
		print(sx, i)
	x = 1
	y = m
	while x <= n:
		if x == sx:
			x += 1
			continue
		if y == m:
			for i in range(m, 0, -1):
				print(x, i)
				y = i
		else:
			for i in range(1, m + 1):
				print(x, y)
				y = i
		x += 1
