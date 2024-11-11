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
from math import log2
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")

a, b = gil()
rev = False
if a > b:
    rev = True
    a, b = b, a

# solving for a

l, r  = 1, int(1e9)
ans = -1

while l <= r:
    mid = (l+r)//2
    if (mid*(mid+1))//2 <= a:
        ans = mid
        l = mid + 1
    else:
        r = mid - 1


newSum = ((ans+1)*(ans+2))//2

miss = inf if newSum - a > ans+1 else newSum - a

# print('miss', miss)

if miss != inf:
    ans += 1

aa, bb = [], []

for v in range(1, ans+1):
    if v != miss:
        aa.append(v)

sm = 0
start = ans+1

while sm + start < b:
    bb.append(start)
    sm += start
    start += 1

if sm + miss <= b:
    bb.append(miss)

if rev:
    aa, bb = bb, aa

print(len(aa))
print(*aa)
print(len(bb))
print(*bb)
