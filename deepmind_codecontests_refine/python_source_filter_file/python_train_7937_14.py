from math import *
from collections import *
from operator import itemgetter
import bisect
from heapq import *
i = lambda: input()
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
I = lambda:list(map(int,input().split()))
chrIdx = lambda x: ord(x)-96
idxChr = lambda x: chr(96+x)


t = ii()

for _ in range(t):
	n = ii()
	a = iia()
	b = [i+1 for i in range(n)]
	#print(b)
	c = []
	for i in range(n):
		c.append(a[i]-(i+1))
	cnt = 0
	nz = 0
	nnz = 0
	ans = 0
	j = 0
	#print(c)
	while j<n:
		i = j
		nz = 0
		nnz = 0
		cz = 0
		while i<n:
			cnt+=c[i]
			if c[i]==0:
				nz+=1
				k = i+1
				while k<n:
					if c[k]==0:
						k+=1
					else:
						break
				i = k-1
			else:
				nnz+=1
			if cnt==0:
				break
			i+=1
		if nnz>0:
			ans+=(nz+1)
		j = i+1 
	print(ans)








