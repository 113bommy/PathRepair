from functools import lru_cache
from sys import stdin, stdout
import sys
from math import *

# from collections import deque
# sys.setrecursionlimit(int(2e5))
input = stdin.readline
# print = stdout.write
# dp=[-1]*100000

n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

ans=inf
for i in range(1,2**9):
	c=0
	for j in range(n):
		for k in range(m):
			if (a[j]&b[k])|i==i:
				c+=1
				break
	if(c==n):
		ans=min(ans,i)
print(ans)