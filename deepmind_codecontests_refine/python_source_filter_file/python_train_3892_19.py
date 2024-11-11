from sys import stdin,stdout,setrecursionlimit
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush,nlargest
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm , accumulate
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
import copy
import time
setrecursionlimit(10**9)
starttime = time.time()
mod = int(pow(10, 9) + 7)
mod2 = 998244353
# from sys import stdin
# input = stdin.readline
#def data(): return sys.stdin.readline().strip()
def data(): return input()
def num():return int(input())
def L(): return list(sp())
def LF(): return list(spf())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def spf(): return map(int, input.readline().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
def pmat(A):
    for ele in A:
        print(*ele,end="\n")
def pmat2(A):
    for ele in A:
        for j in ele:
            print(j,end='')
        print()
def iseven(n):
    return n%2==0

def seive(r):
    prime=[1 for i in range(r+1)]
    prime[0]=0
    prime[1]=0
    for i in range(r+1):
        if(prime[i]):
            for j in range(2*i,r+1,i):
                prime[j]=0
    return prime
#solution
#ACPC 
#remeber cut ribbon problem
# set data structures faster than binary search sometimes
#bipartite match dfs
#think in problems with recursive manner.
a=input()
HM={}
for i in a:
    HM[i]=HM.get(i,0)+1
odd_count=0
for i,v in HM.items():
    if v%2==1:
        odd_count+=1
if odd_count>2:
    print("Frist")
else:
    if odd_count%2==0:
        print("Second")
    else:
        print("Frist")


    
endtime = time.time()
#print(f"Runtime of the program is {endtime - starttime}")