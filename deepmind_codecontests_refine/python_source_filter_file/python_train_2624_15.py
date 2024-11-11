
from math import ceil
from math import factorial
import collections
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
 
t = ii()
 
for i in range(t):
	x,y = iia()
	if(y==1):
		print(y**2)
	elif(x==1):
		print(y**2)
	else:
		if(y>x):
			a=y//x
			b=y%x
			c=(a+1)**2*b+(x-b)*a**2
			print(c)
		else:
			print(x)