import math as ma
import sys
from sys import exit
from decimal import Decimal as dec
from itertools import permutations


def li():
	return list(map(int , input().split()))


# https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
def modInverse(a , m):
	m0 = m
	y = 0
	x = 1
	if (m == 1):
		return 0
	while (a > 1):
		q = a // m
		t = m
		m = a % m
		a = t
		t = y
		y = x - q * y
		x = t
	if (x < 0):
		x = x + m0
	return x


def num():
	return map(int , input().split())


def nu():
	return int(input())


def find_gcd(x , y):
	while (y):
		x , y = y , x % y
	return x

n=nu()
a=li()
s=[0]*101
qq=[[] for y in range(101)]
for i in range(n):
	s[a[i]]+=1
	qq[a[i]].append(i)
c=0
x=0
o=0
e=0
for i in range(101):
	if(s[i]==0):
		continue
	if(s[i]==1):
		c+=1
	if(s[i]>1):
		x+=1
	if(s[i]%2==1):
		o+=1
	if(s[i]%2==0 and s[i]>2):
		e+=1
o=o-c
if(c==0 and x>0):
	print("YES")
	cc = 0
	ap = [0] * n
	for i in range(101):
		if (s[i] == 0):
			continue
		if (cc == 0):
			for j in range(len(qq[i])):
				ap[qq[i][j]] = "A"
			cc = 1
		else:
			for j in range(len(qq[i])):
				ap[qq[i][j]] = "A"
			cc = 0
	print(*ap , sep="")
elif(c>0 and x==0):
	if(c%2==1):
		print("NO")
	else:
		print("YES")
		cc=0
		ap=[0]*n
		for i in range(101):
			if(s[i]==0):
				continue
			if(cc==0):
				ap[qq[i][0]]="A"
				cc=1
			else:
				ap[qq[i][0]] = "B"
				cc = 0
		print(*ap , sep="")
else:
	if(c%2==0):
		print("YES")
		cc = 0
		ap = [0] * n
		for i in range(101):
			if(s[i]==0):
				continue
			if(s[i]>1):
				for j in range(len(qq[i])):
					ap[qq[i][j]] = "A"
			else:
				if (cc == 0):
					ap[qq[i][0]] = "A"
					cc = 1
				else:
					ap[qq[i][0]] = "B"
					cc = 0
		print(*ap , sep="")
	else:
		if(o>0 or e>0):
			print("YES")
			cc = 0
			ap = [0] * n
			aq=0
			if(o>0):
				aq=1
			else:
				aq=0
			kk = 0
			for i in range(101):
				if (s[i] > 1 and s[i]%2==aq):
					kk = i
					ap[qq[i][0]] = "B"
					for j in range(1 , len(qq[i])):
						ap[qq[i][j]] = "A"
					break
			for i in range(101):
				if (s[i] == 0 or i == kk):
					continue
				if (s[i] > 1):
					for j in range(len(qq[i])):
						ap[qq[i][j]] = "A"
				else:
					if (cc == 0):
						ap[qq[i][0]] = "A"
						cc = 1
					else:
						ap[qq[i][0]] = "B"
						cc = 0
			print(*ap , sep="")
		else:
			print("NO")