from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd,log
from collections import deque
from bisect import bisect_left,bisect_right
for _ in range(int(input())):
	l,r,m=map(int,input().split())
	c=l
	t=min(m,r-l)
	for i in range(l,r+1):
		z=m%i
		if z<=t and (m-z)!=0:
			print(i,c+z,c)
			break
		else:
			z=i-z
			if z<=t and (m+z)!=0:
				print(i,l,l+z)
				break