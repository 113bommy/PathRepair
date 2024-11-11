import math as ma
from sys import exit
from decimal import Decimal as dec
def li():
	return list(map(int,input().split()))
def num():
	return map(int,input().split())
def nu():
	return int(input())
n,b=num()
a=li()
o=0
e=0
tt=0
v=b
cost=[]
for i in range(n-1):
	if(a[i]%2==0):
		e+=1
	else:
		o+=1
	if(o==e):
		cost.append(abs(a[i]-a[i+1]))
cost.sort()
c=0
for i in range(len(cost)):
	if(cost[i]<v):
		c+=1
		v=v-cost[i]
print(c)