import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
# from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var): sys.stdout.write(' '.join(map(str, var)) + '\n')
def out(var): sys.stdout.write(str(var) + '\n')
from decimal import Decimal
# from fractions import Fraction
# sys.setrecursionlimit(100000)
mod = int(1e9) + 7
INF=float('inf')


n,m,k,t=mdata()
a=sorted(mdata())
trap=sorted([mdata() for i in range(k)],key=lambda x:x[0])
t-=n+1
start,end=0,n-1
while start<=end:
    mid=(start+end)//2
    walk=0
    i,j=-1,-2
    for l,r,d in trap:
        if d>a[mid]:
            if l<=j:
                j=max(r,j)
            else:
                walk+=j-i+1
                i,j=l,r
    walk+=j-i+1
    if 2*walk<=t:
        end=mid-1
    else:
        start=mid+1
out(n-start)