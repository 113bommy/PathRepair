import math as ma
from sys import exit
from decimal import Decimal as dec


def li():
	return list(map(int , input().split()))


def num():
	return map(int , input().split())


def nu():
	return int(input())

a,b,x=num()
pp=0
ut=0
zulmi=0
if(a>=b):
	pp=1
	ut=0
	zulmi=a
else:
	pp=0
	ut=1
	zulmi=b
v=[ut]*(a+b)
if(x%2==1):
	z=(x-1)//2
else:
	z=x//2
if(x%2==0):
	v[0]=pp
	z=z-1
	p=z
	ll=2
	while(p>0):
		v[ll]=pp
		p-=1
		ll+=2
	#print(v)
	for j in range(zulmi+z+1,(a+b)):
		#print(j)
		v[j]=pp
else:
	ll=1
	p=z
	#print(p)
	while (p > 0):
		v[ll] = pp
		p -= 1
		ll += 2
	for j in range(zulmi+z, (a + b)):
		v[j] = pp
print(*v,sep="")