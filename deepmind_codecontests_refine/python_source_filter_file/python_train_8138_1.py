import io, sys, atexit, os
import math as ma
from sys import exit
from decimal import Decimal as dec
from itertools import permutations
from itertools import combinations


def li ():
	return list (map (int, sys.stdin.readline ().split ()))


def num ():
	return map (int, sys.stdin.readline ().split ())


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

def solve ():
	t = 1
	for tt in range (t):
		n,m=num()
		a=li()
		p=[0]*(n+1)
		for i in range(0,m-1):
			if(a[i]==a[i+1]):
				continue
			l=a[i]
			r=a[i+1]
			if(l>r):
				l,r=r,l
			hp=r-l
			kp=l-1
			ko=r-1
			p[ko+1]+=hp
			p[n]-=hp
			p[kp]-=hp
			p[0]+=hp
			p[kp+1]+=hp-1
			p[ko]-=(hp-1)
			p[ko]+=(l-1)
			p[ko+1]-=(l-1)
			p[kp]+=(r-1)
			p[kp+1]-=(r-1)
		for i in range(1,n+1):
			p[i]=p[i]+p[i-1]
		print(*(p[0:n]))
















if __name__ == "__main__":
	solve ()