import sys

def input(): return sys.stdin.readline().rstrip("\r\n")

def maps():return [int(i) for i in input().split()]

#lOOKOUT FOR THE EDGE CASES
from math import ceil
for i in range(*maps()):
	n , s = maps()
	if n == 1:
		print(s)
		continue
	if s == n :
		print(1)
		continue

	# N = n - 1
	# if s < N*(N+1)//2 :
	# 	print()
	m = ceil(n/2) + (1 if n%2 == 0 else 0)
	
	print(s//m)
	