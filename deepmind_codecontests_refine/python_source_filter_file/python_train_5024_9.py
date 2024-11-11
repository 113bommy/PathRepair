import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write('\n'.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7



for t in range(int(data())):
    n=int(data())
    a=sorted(mdata(),reverse=True)
    x,y=0,0
    s=0
    l=[0]*32
    for i in range(n):
        s = s ^ a[i]
        for j in range(32):
            if (1<<j)&a[i]:
                l[j]+=1
    if s==0:
        out("DRAW")
        continue
    if n%2==0:
        out("WIN")
    else:
        for i in range(31,-1,-1):
            if l[i]%2!=0:
                if l[i]==1:
                    out("WIN")
                else:
                    out("LOSE")
                break

