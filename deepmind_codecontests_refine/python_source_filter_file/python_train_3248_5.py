import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import *
# import math
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
# sys.setrecursionlimit(int(pow(10, 2)))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = int(pow(10, 9) + 7)
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]





# @lru_cache(None)
n=l()[0]
A=l()
s=set()
enc=set()
ans=[]
count=0
for i in range(n+1):
    if(i!=0 and len(s)==0):
        ans.append(count)
        count=0
        enc=set()
        if(i==n):
            break
    if(i==n):
        break
    if(A[i]>0 and A[i] not in s):
        if(A[i] in enc):
            ans=-1
            break
        s.add(A[i])
        enc.add(A[i])
    elif(A[i]>0 and A[i] not in s):
        ans=-1
        break
    elif(A[i]<0 and -A[i] in s):
        s.discard(-A[i])
    elif(A[i]<0 and -A[i] not in s):
        ans=-1
        break
    count+=1

if(ans==-1 or len(s)!=0):
    print(-1)
    exit()
if(ans==[]):
    print(1)
    print(n)
    exit()
print(len(ans))
for ele in ans:
    print(ele,end=" ")

