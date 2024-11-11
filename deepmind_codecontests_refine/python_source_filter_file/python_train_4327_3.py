#!/usr/bin/env	python
#-*-coding:utf-8 -*-
y,x=map(int,input().split())
N=3
L=N*[y]
y=i=0
while x>L[i]:
	j=(1+i)%N
	L[i]=L[(i-1)%N]-1+L[j]
	i=j
	y+=1
print(y)
