from sys import stdin
input=lambda : stdin.readline().strip()
lin=lambda :list(map(int,input().split()))
iin=lambda :int(input())
main=lambda :map(int,input().split())
from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left
mod=998244353
mod=1000000007
def gcd(a,b):
	a,b=max(a,b),min(a,b)
	while a%b!=0:
		a,b=b,a%b
	return b
def moduloinverse(a):
	return(pow(a,mod-2,mod))
def solve(we):
	n,m=main()
	fib=[1,1]
	for i in range(max(n,m)+3):
		fib.append((fib[-1]+fib[-2])%mod)
	print(2*(fib[n]+fib[m]-1))
qwe=1
# qwe=iin()
for _ in range(qwe):
	solve(_+1)