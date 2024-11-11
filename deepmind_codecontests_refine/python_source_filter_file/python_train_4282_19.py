from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
n,k=map(int,input().split())
l=list(map(int,input().split()))
if sum(l)<k:
	print(-1)
else:
	t=0
	m=min(l)
	for i in range(n):
		t+=l[i]-m
		l[i]=m
	if t>=k:
		print(m)
	else:
		k-=t
		t=ceil(k/m)
		print(m-t)