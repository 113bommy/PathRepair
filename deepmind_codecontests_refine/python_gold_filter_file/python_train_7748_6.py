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

def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
try:
    # sys.setrecursionlimit(int(pow(10,4)))
    sys.stdin = open("input.txt", "r")
    # sys.stdout = open("../output.txt", "w")
except:
    pass
def pmat(A):
    for ele in A:
        print(*ele,end="\n")
# def seive():
#     prime=[1 for i in range(10**6+1)]
#     prime[0]=0
#     prime[1]=0
#     for i in range(10**6+1):
#         if(prime[i]):
#             for j in range(2*i,10**6+1,i):
#                 prime[j]=0
#     return prime


n,k=L()
dp=[[0 for i in range(k)] for j in range(n+1)]
for i in range(n+1):
    dp[i][0]=1
for i in range(k-1):
    for j in range(1,n+1):
        for m in range(j,n+1,j):
            dp[m][i+1]=(dp[j][i]+dp[m][i+1])%mod

# pmat(dp)
print(sum(dp[i][-1] for i in range(1,n+1))%mod)



endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")
