import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
# from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var): sys.stdout.write('\n'.join(map(str, var)) + '\n')
def out(var): sys.stdout.write(str(var) + '\n')
from decimal import Decimal
# from fractions import Fraction
# sys.setrecursionlimit(100000)
mod = 10**9+7
INF=float('inf')

n=int(data())
s=data()
a,ab,abc=0,0,0
cnt=0
t=1
for i in s:
    if i=='a':
        a=(a+1)%mod
    elif i=='b':
        ab=(ab+a)%mod
    elif i=='c':
        abc=(abc+ab)%mod
    else:
        abc=(3*abc+ab)%mod
        ab = (3*ab+a)%mod
        a=(3*a+t)%mod
        t=(t*3)%mod
out((abc)%mod)

