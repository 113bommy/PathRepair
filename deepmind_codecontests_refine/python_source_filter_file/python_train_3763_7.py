# -*- coding: utf-8 -*-

import sys
from collections import Counter
if sys.version_info.minor >= 5: from math import gcd
else: from fractions import gcd 

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

N=INT()
A=LIST()
B=LIST()

l=[None]*N
cnt0=0
for i in range(N):
    if A[i]==0 and B[i]==0:
        cnt0+=1
    if A[i]==0:
        continue
    _gcd=gcd(B[i], A[i])
    is_plus=None
    if B[i]/A[i]>0:
        is_plus=True
    elif B[i]/A[i]<0:
        is_plus=False
    l[i]=(is_plus, abs(B[i]//_gcd), abs(A[i]//_gcd))

C=Counter(l)
mx=0
for k, v in C.items():
    if k==INF:
        continue
    mx=max(mx, v)
print(mx+cnt0)
