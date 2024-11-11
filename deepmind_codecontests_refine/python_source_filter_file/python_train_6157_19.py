# -*- coding: utf-8 -*-

import sys, re
from collections import deque, defaultdict, Counter
from math import sqrt, hypot, factorial, pi, sin, cos, radians, log10
if sys.version_info.minor >= 5: from math import gcd
else: from fractions import gcd 
from heapq import heappop, heappush, heapify, heappushpop
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import copy, deepcopy
from functools import reduce, partial
from fractions import Fraction
from string import ascii_lowercase, ascii_uppercase, digits

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def round(x): return int((x*2+1) // 2)
def fermat(x, y, MOD): return x * pow(y, MOD-2, MOD) % MOD
def lcm(x, y): return (x * y) // gcd(x, y)
def lcm_list(nums): return reduce(lcm, nums, 1)
def gcd_list(nums): return reduce(gcd, nums, nums[0])
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

x,y=MAP()
init=(x,y)
x,y=MAP()
dest=(x,y)
N=INT()
S=input()

d=[None]*(N+1)
d[0]=(0,0)
for i in range(N):
    x,y=d[i]
    if S[i]=='L':
        x-=1
    elif S[i]=='R':
        x+=1
    elif S[i]=='U':
        y+=1
    else:
        y-=1
    d[i+1]=(x,y)

def calc(k):
    a=k//N
    b=k%N
    x=init[0]+d[N][0]*a+d[b][0]
    y=init[1]+d[N][1]*a+d[b][1]
    dist=abs(x-dest[0])+abs(y-dest[1])
    return dist

low=0
hi=10**9*4
while low+1<hi:
    mid=(hi+low)//2
    if calc(mid)<=mid:
        hi=mid
    else:
        low=mid
if hi==10**9*4:
    print(-1)
else:
    print(hi)
