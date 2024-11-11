 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
# from __future__ import print_function # for PyPy2
from itertools import permutations as perm
# from fractions import Fraction
from collections import *
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
ans = []
m = 2

for k in range(1, n+1):
	i = k*((k+1)**2) - (m//k)
	print(m)
	m = k*(k+1)

