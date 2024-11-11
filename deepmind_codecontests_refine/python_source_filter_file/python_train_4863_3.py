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
		pre=[0]*300005
		suff=[0]* 300005
		for i in range(n):
			s=input()
			xp=0
			for i in range(len(s)):
				if(s[i]=="("):
					xp+=1
				else:
					xp-=1
				if(xp<0):
					break
			if(xp>=0):
				pre[xp]+=1
			xp=0
			for i in range(len(s)-1,-1,-1):
				if(s[i]=="("):
					xp-=1
				else:
					xp+=1
				if(xp<=0):
					break
			if(xp>=0):
				suff[xp]+=1
		ss=0
		for i in range(n):
			ss+=pre[i]*suff[i]
		print(ss)





if __name__ == "__main__":
	solve ()