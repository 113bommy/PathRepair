#!/usr/bin/env	python
#-*-coding:utf-8 -*-
import sys
n=int(input())
if 2>n:
	print(1)
	sys.exit()
A=tuple(list(map(int,input().split()))for _ in range(n))
s=0
for i in range(n):
	for j in range(n):
		if not A[i][j]:
			s=1
			break
	if s:break
s=sum(A[not i])
A[i][j]=x=s-sum(A[i])
if 1>x or s!=sum(A[i][-1-i]for i in range(n))or sum(A[-1-i][i]for i in range(n))!=s:
	print(-1)
	sys.exit()
for i in range(n):
	if s!=sum(A[i])or sum(A[j][i]for j in range(n))!=s:
		print(-1)
		sys.exit()
print(x)
