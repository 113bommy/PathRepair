import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n, s = mints()
a = [0]*(s+1)
for i in range(n):
	f,t = mints()
	a[f] = max(a[f], t)
for i in range(s-2, -1, -1):
	a[i] = max(a[i+1]+1,a[i])
print(a[0])
