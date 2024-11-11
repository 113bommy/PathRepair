import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
import copy
import time
starttime = time.time()
mod = int(pow(10, 9) + 7)
mod2 = 998244353
from sys import stdin
input = stdin.readline
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
try:
    # sys.setrecursionlimit(int(pow(10,6)))
    sys.stdin = open("input.txt", "r")
    # sys.stdout = open("../output.txt", "w")
except:
    pass


n=L()[0]
A=L()
A.sort()
l=0
r=10**10
while(l<=r):
    t=(l+r)//2
    z=0
    for i in range(n):
        z+=max(0,t-A[i])

    if z<t:
        l=t+1
    else:
        ans=t
        r=t-1
print(ans)




endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")