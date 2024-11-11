from math import *

n=int(input())

l=(-1+sqrt(1+4*n))/2

if l==int(l):
	print("YES")
else:
	print("NO")