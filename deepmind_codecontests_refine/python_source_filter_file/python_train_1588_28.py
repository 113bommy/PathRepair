from collections import Counter
import math
import sys
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7

for _ in range(INT()):
	x = INT()
	#string = input()
	#a,b,c,d = MAP()
	#arr = LIST()
	n = 2*x
	rad = 1/math.sin(3.141592653589/n)
	print(rad)
	

	