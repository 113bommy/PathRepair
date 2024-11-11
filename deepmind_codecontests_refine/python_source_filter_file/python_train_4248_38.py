import math
N=int(input())
a=0
b=50
if N%2!=0:
	print(0)
else:  
	while N>=b:
		a+=N//b
		b*=5
	print(a)