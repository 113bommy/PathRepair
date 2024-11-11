 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
from __future__ import print_function # for PyPy2
# from itertools import permutations
# from functools import cmp_to_key  # for adding custom comparator
# from fractions import Fraction
from collections import *
from sys import stdin
from bisect import *
from heapq import *
from math import log2, ceil, sqrt
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")

n, x1, y1, x2, y2 = gil()
p = [gil() for _ in range(n)]

p.sort(key=lambda x:((x[0]-x1)**2) + ((x[1]-y1)**2))


r = [0]*(n+1)
for i in reversed(range(n)):
    r[i] = max(r[i+1], (((p[i][0]-x2)**2) + ((p[i][1]-y2)**2)))
ans = r[0]**2
for i in range(n):
    ans = min(ans, (((p[i][0]-x1)**2) + ((p[i][1]-y1)**2)) + r[i+1])


x1, y1, x2, y2 = x2, y2, x1, y1

p.sort(key=lambda x:((x[0]-x1)**2) + ((x[1]-y1)**2))


r = [0]*(n+1)
for i in reversed(range(n)):
    r[i] = max(r[i+1], (((p[i][0]-x2)**2) + ((p[i][1]-y2)**2)))
ans = min(ans, r[0]**2)

for i in range(n):
    ans = min(ans, (((p[i][0]-x1)**2) + ((p[i][1]-y1)**2)) + r[i+1])

print(ans)