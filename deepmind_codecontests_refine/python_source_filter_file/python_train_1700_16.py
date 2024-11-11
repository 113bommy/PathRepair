import math
import sys
inp=int(input())

for _ in range(inp):
	input()
	temp=float('inf')
	n,k=map(int,input().split(" "))
	a=list(map(int,input().split(" ")))
	t=list(map(int,input().split(" ")))
	c=[temp]*n
	for i in range(k):
		c[a[i]-1]=t[i]
	L=[temp]*n
	R=[temp]*n
	p=temp*n
	for i in range(n):
		p=min(p+1,c[i])
		L[i]=p
	p=temp
	res=[0]*n
	for i in range(n-1,-1,-1):
		p=min(p+1,c[i])
		res[i]=min(L[i],p)
	print(res)




# from wrapt_timeout_decorator import *
# @timeout(2.5)
# def i():
# 	p=0

# try:
# 	i()
# except Exception:
# 	print("TLE")