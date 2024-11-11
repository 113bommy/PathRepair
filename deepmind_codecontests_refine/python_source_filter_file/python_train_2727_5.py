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
import math
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]
    return inf


def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return i-1
    return -inf


n, m = gil()
row, col = gil(), gil()
mat = [[2 for _ in range(m)] for _ in range(n)]
for r in range(n):
	for c in range(row[r]):
		if mat[r][c] == 0:print(0);exit()
		mat[r][c] = 1
	if row[r] < m :
		if mat[r][row[r]] == 1:print(0);exit()
		mat[r][row[r]] = 0

for c in range(m):
	for r in range(col[c]):
		if mat[r][c] == 0:print(0);exit()
		mat[r][c] = 1
	if col[c] < n :
		if mat[col[c]][c] == 1: print(0);exit()
		mat[col[c]][c] = 0

# for r in mat:
# 	print(r)

p = 0
for r in mat:
	p += r.count(2)

if p == 0:
	print(p)
	exit()

ans = 2**p

ans %= mod
print(ans)


