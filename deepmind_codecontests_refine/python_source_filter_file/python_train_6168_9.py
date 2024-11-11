import collections
import itertools
from functools import lru_cache
import sys
import math
##################################################################

#Helper
def helper():
	pass
##################################################################
#Solver
def solve():
	n, k = map(int, input().split(' '))
	s = input()
	slist = sorted(list(s))
	if k==1:
		print(''.join(slist))
	elif len(set(slist)) == 1:
		print(slist[0] * (math.ceil(n / k)))
	else:
		if k == n:
			print(slist[k - 1])
		else:
			if slist[0] == slist[k - 1]:
				if len(set(slist[k:])) == 1:
					print(''.join(slist[0]) + slist[k]*(math.ceil(len(slist[k:])//k)))
				else:
					print(''.join(slist[0]) + ''.join(slist[k:]))
			else:
				print(slist[k-1])
#################################################################			
#Driver
t = int(input())

for _ in range(t):
	solve()
################################################################
