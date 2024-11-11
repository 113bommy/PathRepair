from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
from bisect import bisect_left
for _ in range(int(input())):
	n,k=map(int,input().split())
	x=list(map(int,input().split()))
	o=list(map(int,input().split()))
	x.sort()
	a=[0 for i in range(n)]
	b=list(a)
	for i in range(n):
		t=bisect_left(x,x[i]-k)
		a[i]=max(a[i-1],i-t+1)
		if t>0:
			b[i]=max(b[i-1],i-t+1+a[t-1])
		else:
			b[i]=max(b[i-1],i-t+1)
		print(a,t)
		print(b)
	print(max(b[-1],a[-1]))