from sys import stdin
from math import sqrt
input=stdin.readline
for _ in range(int(input())):
	n=int(input())
	a=[1]+list(map(int,input().split()));v=[1]*(n+1)
	for i in range(1,n//2+2):
		for j in range(i*2,n+1):
			if a[i]<a[j]:v[j]=max(v[i]+1,v[j])
	print(max(v))