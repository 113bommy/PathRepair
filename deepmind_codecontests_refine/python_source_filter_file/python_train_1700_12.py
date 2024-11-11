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
import sys
# from bisect import *
from heapq import *
from math import log2, ceil, sqrt, gcd, log
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")
# range = xrange

t, = gil()
for _ in range(t):
    g()
    n, k = gil()
    ans = [inf]*(n+1)

    for pos, temp in zip(gil(), gil()):
        ans[pos] = temp

    for i in range(1, n):
        ans[i+1] = min(ans[i+1], ans[i]+1)

    for i in reversed(range(1, n)):
        ans[i-1] = min(ans[i-1], ans[i]+1)


    print(*ans[1:])