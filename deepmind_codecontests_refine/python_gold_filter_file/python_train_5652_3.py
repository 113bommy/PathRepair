import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
sys.setrecursionlimit(100000)
INF = float('inf')
mod = 998244353

n=int(data())
a=mdata()
x=0
for i in a:
    x^=i
if n%2==0 and x:
    out("NO")
    exit()
out("YES")
out(n-2+n%2)
for i in range(1,n-1+n%2,2):
    outl([1,i+1,i+2])
for i in range(1,n-1+n%2,2):
    outl([1,i+1,i+2])