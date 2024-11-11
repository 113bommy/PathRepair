from collections import Counter
import math
import sys
from bisect import bisect,bisect_left,bisect_right
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7

for _ in range(int(input())):
	n = INT()
	# s = input()
	#n,k = MAP()
	#arr = LIST()
	a = []

	for i in range(n):
		x = input()
		arr = [int(i) for i in x]
		arr.append(11)
		a.append(arr)
	x = []
	for i in range(n):
		x.append(11)
	a.append(x)
	#print(a)
	flag = 0
	for i in range(n):
		for j in range(n):
			if a[i][j] == 1:
				if a[i+1][j] == 0 or a[i][j+1] == 0:
					flag = 1
					break
	if flag == 1:
		print("NO")
	else:
		print("YES")
