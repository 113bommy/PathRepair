from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
for _ in range((int(input()))):
	a,b,c,d=map(int,input().split())
	time=0
	if a<=b:
		print(a)
	else:
		a=a-b
		time+=b
		if d>=c:
			print(-1)
		else:
			t=c-d
			time+=c*(ceil(a/t))
			print(time)
