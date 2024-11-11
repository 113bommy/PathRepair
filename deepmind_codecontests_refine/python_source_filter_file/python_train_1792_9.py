from sys import stdin,stdout,setrecursionlimit
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C,deque
from math import ceil,gcd,sqrt,factorial,log2,floor
from bisect import bisect_right as br,bisect_left as bl
import heapq
from itertools import groupby


l = list(input())
n = len(l)

v=[]
for i,j in groupby(l):
	# print(i,list(j))
	v.append((i,len(list(j))))
# print(v)

if not len(v)&1:
	print(0)
	exit()

if len(v) ==1:
	if v[0][1]>2:
		print(v[0][1]+1)
		exit()
	else:
		print(0)
		exit()

if v[len(v)//2][1] < 2:
	print(0)
	exit()

t = len(v)

i,j = t//2 - 1,t//2 + 1

while i>=0 and j<t:
	if v[i][0] != v[j][0]:
		print(0)
		exit()
	else:
		if v[i][1]+v[j][1] < 3:
			print(0)
			exit()
	i -= 1
	j += 1
print(v[t//2][1]+1)
	
