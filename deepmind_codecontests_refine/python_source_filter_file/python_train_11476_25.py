import collections as cc
import math as mt
import sys
I=lambda:list(map(int,input().split()))
n,m=I()
a=I()
su=1
if n>m:
	print(0)
else:
	for i in range(n):
		for j in range(i+1,n):
			su*=(a[j]-a[i])%m
			su%=m

	print(su)