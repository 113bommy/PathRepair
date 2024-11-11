import math as ma
import sys
from sys import exit
from decimal import Decimal as dec
from itertools import permutations


def li():
	return list(map(int , sys.stdin.readline().split()))


def num():
	return map(int , sys.stdin.readline().split())


def nu():
	return int(sys.stdin.readline())


def find_gcd(x , y):
	while (y):
		x , y = y , x % y
	return x

n=nu()
s=input()
x,y=num()
uu=[0]*n
rr=[0]*n
pu=[]
pr=[]
for i in range(n):
	if(s[i]=="U"):
		uu[i]=1
	if(s[i]=="D"):
		uu[i] = -1
	if(s[i]=="R"):
		rr[i]=1
	if(s[i]=="L"):
		rr[i]=-1

pu.append(uu[0])
pr.append(rr[0])
for i in range(1,n):
	pu.append(pu[i-1]+uu[i])
for i in range(1,n):
	pr.append(pr[i-1]+rr[i])
pu=[0]+pu
pr=[0]+pr
zu=pu[len(pu)-1]
zr=pr[len(pr)-1]
if((abs(x-zu)+abs(y-zr))==0):
	print(0)
	exit(0)
if((abs(x)+abs(y))%2!=n%2 or (abs(x)+abs(y))>n):
	print(-1)
	exit(0)

lo=1
hi=n
while(lo<=hi):
	mid=(lo+hi)//2
	fl=False
	for i in range(0,n-mid+1):
		lu=zu-pu[i+mid]+pu[i]
		lr=zr-pr[i+mid]+pr[i]
		if((abs(x-lr)+abs(y-lu))<=mid):
			fl=True
			break
	if(fl==True):
		hi=mid-1
	else:
		lo=mid+1
print(lo)