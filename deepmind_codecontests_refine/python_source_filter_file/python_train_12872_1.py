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
a, b = g(), g()
edges = set()
for i in range(n):
	if a[i] != b[i]:
		edges.add((a[i], b[i]))
		edges.add((b[i], a[i]))

dsu = list(range(26))
cnt = [1]*26
ans = []

def getParent(x):
	while dsu[x] != x:
		x = dsu[x]
	return x


while edges:
	ai, bi = edges.pop()
	edges.remove((bi, ai))
	x, y = ord(ai)-97, ord(bi)-97
	px, py = getParent(x), getParent(y)
	if px == py: continue
	ans.append((ai, bi))
	if cnt[px]  >= cnt[py]:
		cnt[px] += cnt[py]
		dsu[y] = x
	else:
		cnt[py] += cnt[px]
		dsu[x] = y


print(len(ans))
if ans:
	for r in ans:
		print(*r)
