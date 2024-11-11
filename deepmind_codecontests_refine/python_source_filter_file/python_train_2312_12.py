from sys import stdin
from collections import deque
from math import sqrt, floor, ceil, log, log2, log10, pi, gcd, sin, cos, asin
def ii(): return int(stdin.readline())
def fi(): return float(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def fmi(): return map(float, stdin.readline().split())
def li(): return list(mi())
def lsi():
	x=list(stdin.readline())
	x.pop()
	return x
def si(): return stdin.readline()
def out():
	print(0, 0, 0)
for _ in range(ii()):
	n=ii()
	a=li()
	g=s=b=0
	f=1
	if a[0]>2 and n>9:
		x=n//2
		x-=1
		if a[x]==a[x+1]:
			f=0
			for i in range(x, 3, -1):
				if a[i]!=a[x]:
					x=i
					f=1
					break
		if f:
			for i in range(1, x+1):
				if a[i]!=a[0]:
					g=i
					break
			for i in range(g+1, x+1):
				if a[i]!=a[i-1] and g<i-g:
					s=i-g
					break
			if a[x]!=a[s+g-1] and g<(x+1)-(g+s):
				b=(x+1)-(g+s)
			#print(g, s, b, x)
			if not b:
				out()
			else:
				print(g, s, b)
		else:
			out()
	else:
		out()