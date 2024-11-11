import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
# import numpy as np
sys.setrecursionlimit(int(pow(10,6)))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("out.txt", "w")
mod = int(pow(10, 9) + 7)
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]

# @lru_cache(None)
t=1
t=int(input())
for _ in range(t):
    n,k=L()
    A=[[0 for i in range(n)] for j in range(n)]
    p=q=0
    for i in range(k):
        A[p][q]=1
        p+=1
        q=(q+1)%n
        if p==n:
            p=0
            q=(q+1)%n
    rmax=cmax=0
    rmin=cmin=10**10
    for i in range(n):
        x=[A[i][j] for j in range(n)]
        rmin=min(rmin,sum(x))
        rmax=max(rmax,sum(x))
        cmin=min(cmin,sum(A[i]))
        cmax=max(cmax,sum(A[i]))
    print((rmin-rmax)**2+(cmin-cmax)**2)
    for i in range(n):
        for j in range(n):
            print(A[i][j],end="")
        print()

