from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
from bisect import bisect_right
n,p=map(int,input().split())
l=list(map(int,input().split()))
t=max(min(l),abs(n-max(l)))
l.sort()
z=[]
for i in range(t,l[-1]+1):
	ans=1
	x=i
	f=1
	for j in range(n):
		ans=bisect_right(l,x+j)
		if (ans-j)%p==0:
			f=0
			break
	if f==1:
		z.append(i)
print(len(z))
print(*z)