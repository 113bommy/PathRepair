import sys
import itertools as it
import bisect as bi
import math as mt
import collections as cc
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
n,m=I()
a=[]
b=[]
c=[]
for i in range(1,int(n**0.5)+1):
	if n%i==0:
		a.append(i)
for i in range(1,int(m**0.5)+1):
	if m%i==0:
		b.append(i)
ne=n+m
for i in range(1,int(ne**0.5)+1):
	if ne%i==0:
		c.append(i)
ans=mt.inf
for i in c[::-1]:
	j=ne//i
	tf=0
	for ii in a:
		if ii<=i and n//ii<=j:
			tf=1
			break
	for jj in b:
		if jj<=i and m//jj<=j:
			tf=1
			break 
	if tf:
		ans=min(ans,2*(i+j))
		break
print(ans)
