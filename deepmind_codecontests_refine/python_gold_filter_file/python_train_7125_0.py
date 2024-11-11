 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   

from __future__ import print_function # for PyPy2
from collections import Counter, OrderedDict
from itertools import permutations as perm
from fractions import Fraction
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
# from math import *

g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf") 
# range = xrange

n, = gil()
a = gil()
ans = 1
l, r = [1]*n, [1]*n

for i in range(1, n):
	if a[i] > a[i-1]:
		l[i] += l[i-1]
	ans = max(ans, l[i]+1)

for i in reversed(range(n-1)):
	if a[i] < a[i+1]:
		r[i] += r[i+1]
	ans = max(ans, r[i]+1)

ans = min(ans, n)
# print(a)
# print(l)

for i in range(1, n-1):
	if a[i+1] - a[i-1] > 1:
		ans = max(ans, r[i+1] + l[i-1] + 1)

print(ans)



