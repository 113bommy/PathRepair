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

n,m,k=R()
A=[L() for i in range(n)]
B=[L() for i in range(n-1)]
if k&1:
	for i in range(n):
		print('-1 '*m)
X=[[0]*m for i in range(n)]
for _ in range(k//2):
	Y=[[inf]*m for i in range(n)]
	for i in range(n):
		for j in range(m):
			if i:
				Y[i][j]=X[i-1][j]+2*B[i-1][j]
			if i<n-1:
				Y[i][j]=min(Y[i][j],X[i+1][j]+2*B[i][j])
			if j:
				Y[i][j]=min(Y[i][j],X[i][j-1]+2*A[i][j-1])
			if j<m-1:
				Y[i][j]=min(Y[i][j],X[i][j+1]+2*A[i][j])
	X=Y
for i in X:
	print(*i)