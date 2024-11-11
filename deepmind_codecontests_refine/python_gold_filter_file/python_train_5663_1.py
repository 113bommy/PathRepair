#!/usr/bin/python3

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def red(pr):
	a, b = pr
	g = gcd(a, b)
	return (a // g, b // g)

def rev(pr):
	a, b = pr
	return (b, a)

def add(pr, i):
	a, b = pr
	a += b * i
	return red((a, b))

import sys
args = list(map(int, sys.stdin.read().split()))
p, q = args[0], args[1]
args = args[2:]
n = args[0]
args = args[1:]
a = args[::-1]
s = (a[0], 1)
a = a[1:]
for i in a:
	s = add(rev(s), i)
if red(s) == red((p, q)):
	print("YES")
else:
	print("NO")
