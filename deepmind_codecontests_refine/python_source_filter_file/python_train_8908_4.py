 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
from __future__ import print_function # for PyPy2
# from itertools import permutations as perm
# from functools import cmp_to_key	# for adding custom comparator
# from fractions import Fraction
from collections import *
from sys import stdin
# from bisect import *
# from heapq import *
from math import *
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

n, = gil()
p, v = gil(), gil()

def inter(l, r, m, n):
	if l > m:
		return inter(m, n, l, r)

	# l <= m
	return max(l, m), min(r, n)

	 
def isPos(t):
	d = v[0]*t
	l, r = p[0] - d, p[0] + d  
	for i in range(1, n):
		d = v[i]*t
		l, r = inter(l, r, p[i] - d, p[i] + d)
		if r < l : return False

	return r >= l


d, l, r = 1e-6, 0, 2e9
ans = None
while l <= r:
	mid = (l+r)/2
	if isPos(mid):
		r = mid - d
		ans = mid
	else:
		l = mid + d

print(round(ans, 6))