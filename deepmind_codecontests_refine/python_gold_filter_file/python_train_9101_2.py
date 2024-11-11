import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
# from math import *
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




n,m=L()
A=[L() for i in range(n)]
A1=[[0 for i in range(m+2)] for j in range(n+2)]
A2=[[0 for i in range(m+2)] for j in range(n+2)]
A3=[[0 for i in range(m+2)] for j in range(n+2)]
A4=[[0 for i in range(m+2)] for j in range(n+2)]
for i in range(1,1+n):
    for j in range(1,1+m):
        A1[i][j]=max(A1[i][j-1],A1[i-1][j])+A[i-1][j-1]
for i in range(n,0,-1):
    for j in range(m,0,-1):
        A2[i][j]=max(A2[i][j+1],A2[i+1][j])+A[i-1][j-1]
for i in range(n,0,-1):
    for j in range(1,1+m):
        A3[i][j]=max(A3[i][j-1],A3[i+1][j])+A[i-1][j-1]
for i in range(1,1+n):
    for j in range(m,0,-1):
        A4[i][j]=max(A4[i][j+1],A4[i-1][j])+A[i-1][j-1]
# for mat in [A1,A2,A3,A4]:
#     for ele in mat:
#         print(ele)
#     print()
ans=0
for i in range(2,n):
    for j in range(2,m):
        ans = max(ans,A1[i][j-1] + A2[i][j+1] + A3[i+1][j] + A4[i-1][j])
        ans = max(ans,A1[i-1][j] + A2[i+1][j] + A3[i][j-1] + A4[i][j+1])
print(ans)

endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")
