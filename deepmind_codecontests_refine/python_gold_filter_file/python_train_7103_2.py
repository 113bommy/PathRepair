from sys import stdin,stdout
from math import *
input = stdin.readline
# print=stdout.write

for __ in range(int(input())):
	n,m=map(int,input().split())
	s=input()
	h=[[0]*26 for i in range(m)]
	for i in range(26):
		for j in range(n):
			if(ord(s[j])-97!=i):
				h[j%m][i]+=1
	ans=0
	for i in range(ceil(m/2)):
		a=inf
		for j in range(26):
			if(i==ceil(m/2)-1 and m%2==1 and a>h[i][j]):
				a=h[i][j]
			elif(h[i][j]+h[-(i+1)][j]<a):
				a=h[i][j]+h[-(i+1)][j]
		ans+=a
	print(str(ans))