from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
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

for _ in range(I()):
	n=I()
	s=S()
	a=s.count('0')
	if s==s[::-1]:print("BOB" if a==1 or a%2==0 else 'ALICE');continue
	dif=0
	for i in range(n):
		if s[i]!=s[-1-i]:dif+=1
	if dif==1 and a==2 and n%2:print('DRAW');continue
	print('ALICE')