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


n, k = gil()
a = gil()
f = {}
r = 0
l = 0
f[a[r]] = f.get(a[r], 0) + 1

while r+1 < n and len(f) + (int(a[r+1] in f)^1) <= k:
	r += 1
	f[a[r]] = f.get(a[r], 0) + 1

start, ln = l, len(f)

while r+1 < n:
	if f[a[l]] == 1:
		del f[a[l]]
	else:
		f[a[l]] -= 1

	l += 1
	while r+1 < n and len(f) + (int(a[r+1] in f)^1) <= k:
		r += 1
		f[a[r]] = f.get(a[r], 0) + 1

	if r - l + 1 >= ln:
		ln = r-l+1
		start = l

print(start+1, start+ln)


