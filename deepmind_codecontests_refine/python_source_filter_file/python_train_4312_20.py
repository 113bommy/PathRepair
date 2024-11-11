from sys import stdin,stdout
input=stdin.readline 
import math,bisect

n=int(input())
l=list(map(int,input().split()))
if n<=2:
	print("No")
else:
	f=0
	for i in range(1,n):
		x1=min(l[i-1],l[i])
		x2=max(l[i-1],l[i])
		for j in range(i+1,n):
			x3=min(l[j-1],l[j])
			x4=max(l[j-1],l[j])
			if x1<x3<x2<x4:
				f=1
			elif x3<x1<x4<x2:
				f=1
	if f==0:
		print("no")
	else:
		print("yes")