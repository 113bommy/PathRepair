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


mm = 998244353
yp = 0

def solve ():
	t = 1
	for tt in range (t):
		n=nu()
		a=[]
		p=[]
		q=[]
		fact=[0]*(n+1)
		fact[0]=1
		for i in range(1,n+1):
			fact[i]=(fact[i-1]*i)%mm
		for i in range(n):
			x,y=num()
			p.append(x)
			q.append(y)
			a.append((x,y))
		a.sort()
		p.sort()
		q.sort()
		cc=1
		last=p[0]
		ans1=1
		for i in range(1,n):
			if(last==p[i]):
				cc+=1
			else:
				ans1=(ans1*fact[cc])%mm
				cc=1
				last=p[i]
		ans1 = (ans1 * fact [ cc ]) % mm
		cc=1
		last=q[0]
		ans2=1
		for i in range(1,n):
			if(last==q[i]):
				cc+=1
			else:
				ans2=(ans2*fact[cc])%mm
				cc=1
				last=q[i]
		ans2 = (ans2 * fact [ cc ]) % mm
		ans3=1
		cc=1
		last=a[0]
		for i in range(1,n):
			if(last==a[i]):
				cc+=1
			elif(last[0]>a[i][0] or last[1]>=a[i][1]):
				ans3=0
			else:
				ans3=(ans3*fact[cc])%mm
				cc=1
				last=a[i]
		ans3 = (ans3 * fact [ cc ]) % mm
		print((fact[n]-ans1-ans2+ans3+mm)%mm)

if __name__ == "__main__":
	solve ()