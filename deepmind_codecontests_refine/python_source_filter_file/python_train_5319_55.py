 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   

# from __future__ import print_function # for PyPy2
from collections import Counter, OrderedDict
from itertools import permutations as perm
from fractions import Fraction
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
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
w, = gil()
lift, land = gil(), gil()

def isPos(fw):
	# print(fw)
	cw = w + fw
	delta = (cw/lift[0])
	fw -= delta
	cw -= delta
	if fw <= 0:
		return False

	for i in range(1, n):
		delta = (cw/land[i])
		fw -= delta
		cw -= delta
		if fw <= 0: return False
		delta = (cw/lift[i])
		fw -= delta
		cw -= delta
		if fw <= 0: return False

	if fw <= 0: return False

	delta = cw/land[0]
	fw -= delta
	return False if fw < 0 else True


ans = -1
l, r = float(0), float(1e9)
d = float(1e-6)
# d = 1
while l <= r:
	mid = (l+r)/2
	if isPos(mid):
		ans = mid
		r = mid - d
	else:
		l = mid + d

print(ans) 
