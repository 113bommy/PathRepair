
# MasterKali

from sys import stdin
from collections import Counter
from math import sqrt, factorial, log10, log, floor, ceil
from itertools import permutations, combinations, combinations_with_replacement

input = stdin.readline
def li(): return list(map(int, input().split()))
def lis(): return list(map(str, input().split()))
def mp(): return map(int, input().split())
def inp(): return int(input())
def inps(): return str(input().strip())
def pr(n): return stdout.write(str(n)+"\n")

INF = float('inf')


def solve():
	n, l, r = mp()

	x = n - l + 1
	y = 1
	for i in range(l-1):
		x+=2**y
		y+=1
		
	mx = 1
	best = 0
	y = 1
	for i in range(r-1):
		mx += 2**y
		if i == r-2:
			best = 2**y
		y+=1
	
	for i in range(n-r):
		mx += best

	print(x, mx)

t = 1
for i in range(t):
	
	solve()

