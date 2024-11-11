#                                               |
#   _` |  __ \    _` |   __|   _ \   __ \    _` |   _` |
#  (   |  |   |  (   |  (     (   |  |   |  (   |  (   |
# \__,_| _|  _| \__,_| \___| \___/  _|  _| \__,_| \__,_|

import sys
import math
import operator as op
from functools import reduce
from sys import maxsize 
from decimal import *
def read_line():
	return sys.stdin.readline()[:-1]
 
def read_int():
	return int(sys.stdin.readline())
	
def read_int_line():
	return [int(v) for v in sys.stdin.readline().split()]

def read_float_line():
	return [float(v) for v in sys.stdin.readline().split()]

def ncr(n, r):
	r = min(r, n-r)
	numer = reduce(op.mul, range(n, n-r, -1), 1)
	denom = reduce(op.mul, range(1, r+1), 1)
	return numer / denom

def nc2(n):
	return n*(n-1)//2
getcontext().prec = 64

t = read_int()
for i in range(t):
	h,c,t = read_int_line()
	if t==h:
		print(1)
		continue

	if 2*t==h+c:
		print(2)
		continue
	x = (h-t)/(2*t-h-c)
	if x<0:
		print(2)
		continue
	if x==int(x):
		print(int(2*x+1))
	else:
		x = int(x)
		v1 = Decimal((2*x+3)*abs(((x*(h+c)+h) - t*(2*x+1))))
		v2 = Decimal((2*x+1)*abs((((x+1)*(h+c)+h) - t*(2*x+3))))
		if v1<v2:
			ans = 2*x+1
		else:
			ans = 2*x+3
		print(ans)
			

