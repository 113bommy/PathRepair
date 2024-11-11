from functools import lru_cache
from sys import stdin, stdout
import sys
from math import *

# from collections import deque
# sys.setrecursionlimit(int(2e5))
# input = stdin.readline
# print = stdout.write
# dp=[-1]*100000

for __ in range(int(input())):
	n=int(input())
	ar=list(map(int,input().split()))
	ar.sort()
	rslt=0
	for i in range(2,100):
		d={}
		for j in range(n):
			if(d.get(ar[j])==None):
				d[ar[j]]=0
			d[ar[j]]+=1
		ans=0
		# print(d)
		for j in range(n):
			if(i>ar[j]):
				a=ar[j]
				b=i-ar[j]
				if(d.get(b)!=None):
					if(a==b and d[a]>1):
						d[b]-=1
						d[a]-=1
						ans+=1
					elif(d[b]>0 and d[a]>0 and b!=0 and a!=b):
						d[b]-=1
						d[a]-=1
						ans+=1
				# print(a,b,ans)
		# print(ans,i)
		rslt=max(ans,rslt)
	print(rslt)

