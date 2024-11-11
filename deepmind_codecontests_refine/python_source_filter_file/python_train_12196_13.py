import io, sys, atexit, os

import math as ma
from sys import exit
from decimal import Decimal as dec
from itertools import permutations
from itertools import combinations


def li ():
	return list (map (int, input ().split ()))


def num ():
	return map (int, input ().split ())


def nu ():
	return int (input ())


def find_gcd ( x, y ):
	while (y):
		x, y = y, x % y
	return x
def prod(n):
	s=1
	while(n!=0):
		s=s*(n%10)
		n=n//10
	return s

def check(xp):
	op=sorted(xp)
	if(op==xp):
		return True


mm = 1000000007
def solve ():
	t = 1
	for it in range (t):
		n=nu()
		xp=[ 15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 7, 4, 4, 5, 16, 17]
		print (xp [ n ])
		continue
		if(n<=7):
			print(xp[n])
		else:
			if(n==8):
				print(30)




if __name__ == "__main__":
	solve ()