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

n,x=L()
A=L()
x-=1
if 0 in A[:x]:
    cnt=0
    while A[x]!=0:
        cnt+=1
        A[x]-=1
        x-=1
    A[x]=cnt
elif 0 in A[x+1:]:
    cnt=0
    for i in range(x+1):
        A[i]-=1
        cnt+=1
    for i in range(n-1,-1,-1):
        if A[i]==0:
            A[i]+=cnt
            break
        A[i]-=1
        cnt+=1

else:
    m=min(A)
    idx=-1
    for i in range(x,-1,-1):
        if A[i]==m:
            idx=i
            break
    if idx==-1:
        for i in range(x+1,n):
            if A[i]==m:
                idx=i
                break
    cnt=0
    # print(idx,m)
    for i in range(n):
        # print(A)
        A[i]-=m
        cnt+=m
        if (idx<=x and idx<=i<=x) or (idx>x and not (x<i<=idx)):
            A[i]-=1
            # print(A)
            cnt+=1

    # print(cnt)
    A[idx]+=cnt
print(*A)



endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")