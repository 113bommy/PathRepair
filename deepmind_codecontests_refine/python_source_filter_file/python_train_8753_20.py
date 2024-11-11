import math as ma
from sys import exit
from decimal import Decimal as dec
def li():
	return list(map(int,input().split()))
def num():
	return map(int,input().split())
def nu():
	return int(input())
n,k,s=num()
if(k>s or k*(n-1)<s):
	print("NO")
else:
	l=[]
	if(s%k==0):
		for i in range(k):
			if(i%2==0):
				l.append(s//k+1)
			else:
				l.append(1)
	else:
		pp=s%k
		for i in range(pp):
			if(i%2==0):
				l.append(s//k+2)
			else:
				l.append(1)
		if(pp%2==0):
			for i in range(pp,k):
				if(i%2==0):
					l.append(s//k+1)
				else:
					l.append(1)
		else:
			for i in range(pp,k):
				if(i%2==1):
					l.append(2)
				else:
					l.append(s//k+1)
	print("YES")
	print(*l)