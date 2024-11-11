from sys import stdin
input = stdin.readline
from heapq import heapify,heappush,heappop,heappushpop
from collections import defaultdict as dd, deque as dq,Counter as C
from math import factorial as f ,ceil,gcd,sqrt,log
from bisect import bisect_left as bl ,bisect_right as br
from itertools import combinations as c,permutations as p
from math import factorial as f ,ceil,gcd,sqrt,log
mp = lambda : map(int,input().split())
it = lambda: int(input())
ls = lambda : list(input().strip())
mt = lambda  r : [ list(mp()) for _ in range(r)]
lcm = lambda a,b : (a*b)//gcd(a,b)
def fibo_n(n):
	return (((1+sqrt(5))/2)**n)/sqrt(5)
mod = 1000000007
k=[0]*201
a,b =mp()
d = dd(lambda :[[0,0]])
al =[]
for __ in range(a):
	l,r = mp()
	k[l]+=1;k[r+1]-=1
	al.append([l,r,__+1])
al.sort()
for i in al:
	d[i[0]].append([i[1],i[2]])
rem,sm={},0
for s in range(len(k)):
	sm+=k[s]
	if sm>b:
		rem[s]=sm-b
curk = list(d.keys())
segments = set()
# print(d)
# # print(curk)
# print(rem)
for bad in  rem:
	if rem[bad]>0:
		seg =0
		prevseg=0
		for ele in curk:
			if ele<=bad and len(d[ele])>1:
				seg = max(seg,d[ele][-1][0])
				if seg>prevseg:
					prevseg =seg
					start = ele
					ind = d[ele][-1][1]
		if seg>0:
			segments.add(ind)
		d[start].pop()
		for bade in rem:
			if rem[bade]>0 and bade>= start and bade<=seg:
				rem[bade]-=1
print(len(segments))
print(*sorted(segments))