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


def lcm ( x, y ):
	gg = find_gcd (x, y)
	return (x * y // gg)


mm = 1000000007
yp = 0


def solve ():
	t = 1
	for _ in range (t):
		n=nu()
		s=input()
		cc=0
		last=""
		xp=[]
		for i in range(n):
			if(len(xp)==0):
				xp.append(s[i])
				continue
			if(len(xp)%2==0):
				xp.append (s [ i ])
				continue
			if(xp[len(xp)-1]==s[i]):
				continue
			xp.append (s [ i ])
			continue
		if(len(xp)%2==1):
			xp.pop(0)
		print(n-len(xp))
		print(*xp,sep = "")



if __name__ == "__main__":
	solve ()