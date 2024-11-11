# -*- coding: utf-8 -*-
#ARC58C
import sys

tmp = input().split()
hoge = list(map(lambda a: int(a), tmp))
n=hoge[0]
k=hoge[1]

d=[]
tmp = input().split()
hoge = list(map(lambda a: int(a), tmp))
for i in range(0,k):
	d.append(hoge[i])

payment=0
for i in range(0,10000-n+1):
	payment=n+i
	for j in range(0,k):
		if(str(d[j]) in str(payment)):
			break
		if(j==k-1):
			print(payment)
			sys.exit()