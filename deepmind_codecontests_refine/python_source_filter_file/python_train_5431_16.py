import collections as cc
import math as mt
import sys
I=lambda:list(map(int,input().split()))
n,=I()
a=[]
for i in range(n):
	a.append(float(input()))
su=0
te=[]
for i in a:
	su+=mt.floor(i)
	te.append(mt.floor(i))
if su==0:
	for i in te:
		print(i)
		sys.exit()
i=0
while su and i<n:
	if a[i]%1!=0:
		su+=1
		te[i]=mt.ceil(a[i])
	
	i+=1
for i in te:
	print(i)
