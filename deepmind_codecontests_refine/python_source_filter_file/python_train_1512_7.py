import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n = mint()
m = list(mints())
a = [0]*20002
s = 0
for i in m:
	a[i] += 1
	s += i
b = s // n
c = s % n
j = 20001
r = 0
for i in range(b):
	while a[i] > 0 and j > b + 1 or (j == b + 1 and a[j] > c):
		if a[j] == 0:
			j -= 1
		else:
			z = min(a[i], a[j])
			a[i+1] += z
			a[i] -= z
			a[j] -= z
			a[j-1] += z
			r += z
print(r)
