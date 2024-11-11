# from functools import lru_cache
from sys import stdin, stdout
import sys
from math import *
# sys.setrecursionlimit(3*int(1e5))
# input = stdin.readline
# print = stdout.write
 
# @lru_cache()

for __ in range(int(input())):
	n=int(input())
	c=0
	a=[0]
	for i in range(1,len(bin(n)[2:])+1):
		if(2**i<n):
			c=c*2+i
			a.append(c)
	# print(a)
	s=bin(n)[2:]
	a=a[::-1]
	# print(s)
	# print(a)
	ans=0
	for i in range(len(s)):
		if(s[i]=='1'):
			ans+=a[i]+len(s)-i
	print(ans)



