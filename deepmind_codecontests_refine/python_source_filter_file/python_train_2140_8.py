from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
from bisect import bisect_left,bisect_right
n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
t=pow(10,9)
b.append(t)
b.insert(0,-t)
z=[0]
for i in range(len(a)):
	x=bisect_left(b,a[i])
	if x:
		# print(x)
		z.append(min(a[i]-b[x-1],b[x]-a[i]))

	else:
		z.append(b[x]-a[i])
print(max(z))