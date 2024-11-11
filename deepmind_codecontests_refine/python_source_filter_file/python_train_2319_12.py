import sys
import itertools as it
import math as mt
import collections as cc
input=sys.stdin.readline
I=lambda:list(map(int,input().split())) 
for tc in range(int(input())):
	n,=I()
	l=I()
	f=cc.defaultdict(int)
	ff=cc.defaultdict(int)
	for i in l:
		if not f[i]:
			f[i]=-1
	for i in range(n):
		ff[l[i]]=max(ff[l[i]],i-f[l[i]])
		f[l[i]]=i
	for i in set(l):
		ff[i]=max(ff[i],n-f[i])	
	ans=[-1]*(n)
	#print(f)

	for i in sorted(set(l),reverse=True):
		d=ff[i]
		ans[d-1]=i
	for i in range(n-1):
		if ans[i]!=-1:
			if ans[i+1]==-1 or ans[i+1]>ans[i]:
				ans[i+1]=ans[i]
	print(ans)
