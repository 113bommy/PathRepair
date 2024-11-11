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
# from sys import stdin
# input = stdin.readline
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
# exit()
n,k=L()
A=L()
A.sort()
pref=[0 for i in range(A[-1]+2)]
for h in A:
    pref[1]+=1
    pref[1+h]-=1
for i in range(1,A[-1]+2):
    pref[i]+=pref[i-1]
cnt=0
i=-1
# print(pref)
while(pref[i-1]!=n):
    curr=0
    while(pref[i-1]!=n and curr+pref[i-1]<k):
        i-=1
        curr+=pref[i]
    cnt+=1
    # print(i,cnt,pref[i])
    # if cnt>A[-1]:
    #     exit()
print(cnt)
endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")