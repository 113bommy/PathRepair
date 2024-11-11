from sys import stdin
from math import *
# input = stdin.readline

for __ in range(int(input())):
	n,m=map(int,input().split())
	s=input()
	ans=0
	g=[]
	x=0
	# temp=0
	for i in range(len(s)):
		if(s[i]=='1'):
			x=i
			break
	y=x+1
	while(y<len(s)):
		if(s[y]=='1'):
			if(y-x-1!=0):
				g.append(y-x-1)
			x=y
		y+=1
	ans=0
	if(len(g)!=0):
		ans=n
	for i in range(len(g)):
		if(g[i]*m<n):
			ans+=g[i]*m
		else:
			ans+=n
	print(ans)