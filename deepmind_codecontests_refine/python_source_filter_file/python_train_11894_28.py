from sys import stdin
input = stdin.readline
from heapq import heapify,heappush,heappop,heappushpop
from collections import defaultdict as dd, deque as dq,Counter as C
from math import factorial as f ,ceil,gcd,sqrt,log
from bisect import bisect_left as bl ,bisect_right as br
from itertools import combinations as c,permutations as p
mp = lambda : map(int,input().split())
it = lambda: int(input())
ls = lambda : list(input().strip())
for i in range(it()):
	a = it()
	if a<3:
		print(-1)
	elif a==4:
		print(2,4,1,3)
	else:
		k = a-3
		for i in range(2,a+1,2):print(i,end =" ")
		if a&1:k-=1
		else:a-=1
		print(k,end=" ")
		for j in range(a,-1,-2):
			if j!=k:print(j,end =" ")
		print()