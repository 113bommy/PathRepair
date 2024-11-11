from math import *
t=int(input())
for i in range(t):
	n=int(input())
	max1=int(log(n,2))+1
	w=(n*(n+1))//2
	p=w-2*( pow(2,max1)-1 ) 
	print(int(p))