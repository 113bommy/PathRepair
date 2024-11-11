import sys,math as mt
import heapq as hp
import collections as cc
import math as mt
import itertools as it
import bisect as bi
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
sys.setrecursionlimit(8*10**5)
a,b=I()
g=mt.gcd(a,b)
div=set()
for i in range(2,int(g**0.5)+1):
	if g%i==0:
		div.add(i)
		div.add(g//i)
div=list(div)+[g]
div.sort()
for tc in range(int(input())):
	x,y=I()
	tf=0
	temp=bi.bisect_right(div,y)
	if x<=div[temp-1] and div[temp-1]<=y:
		print(div[temp-1])
	else:
		print(-1)
