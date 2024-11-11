from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
from heapq import heapify,heappush,heappop,heappushpop
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\r\n')
L=lambda:list(R())
P=lambda x:stdout.write(str(x)+'\n')
lcm=lambda x,y:(x*y)//gcd(x,y)
nCr=lambda x,y:(f[x]*inv((f[y]*f[x-y])%N))%N
inv=lambda x:pow(x,N-2,N)
sm=lambda x:(x**2+x)//2
N=10**9+7

n=I()
a=sorted(R())
d=defaultdict(int)
for i in a:
	d[i]=1	
mx=max(a)
ans=[]
ln=0
for i in a:
	p=1
	b=[i]
	x=1
	while i+x<=mx:
		if d[i+x]:
			p+=1
			b+=i+x,
		else:
			p=1
			b=[i]
		if p>ln:
			ln=p
			ans=b.copy()
		if ln==3:
			print(ln)
			print(*ans)
			exit()
		x<<=1
print(ln)
print(*ans)