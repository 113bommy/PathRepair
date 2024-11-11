
# Problem: B. Card Constructions
# Contest: Codeforces - Codeforces Round #639 (Div. 2)
# URL: https://codeforces.com/contest/1345/problem/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# Powered by CP Editor (https://github.com/cpeditor/cpeditor)

from sys import stdin
def get_ints(): return list(map(int, stdin.readline().strip().split()))
from math import floor
a = [0]*10000
a[0] = 2
for i in range(1,10000):
	a[i] = a[i-1]+(i+1)*2 + i
for _ in range(int(input())):
	n = int(input())
	low = 0
	high = len(a)
	res = -1
	c=0
	while n >1:
		low = 0
		high = len(a)
		res = -1
		while low <=high:
			mid = floor((low+high)/2)
			if mid >= len(a):
				mid = len(a)-1
				res = mid
				break
			if a[mid] == n:
				res = mid
				break
			elif a[mid] < n:
				low = mid+1
				res=  mid
			elif a[mid] >n:
				high = mid-1
		if res == -1:
			break
		else:
			n-=a[res]
			c+=1
		
	# print(res)	
	print(c)
	