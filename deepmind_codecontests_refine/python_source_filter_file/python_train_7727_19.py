from sys import stdin
input=lambda : stdin.readline().strip()
lin=lambda :list(map(int,input().split()))
iin=lambda :int(input())
main=lambda :map(int,input().split())
from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left
def gcd(a,b):
	a,b=max(a,b),min(a,b)
	while a%b!=0:
		a,b=b,a%b
	return b
mod=998244353
def solve():
	n=iin()
	z=[]
	for i in range(1,n):
		x=2*9*pow(10,n-i-1,mod)*10
		if i<n-1:
			x+=(n-1-i)*9*9*10*pow(10,n-i-2,mod)*10
		z.append(x)
	z+=[10]
	print(*z)
	
qwe=1	
# qwe=int(input())
for _ in range(qwe):
	solve()
