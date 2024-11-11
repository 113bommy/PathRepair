import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7

n,m=mdata()
l=mdata()
s=[0]*(m+1)
s[-2]=l[-1]
for i in range(m-2,-1,-1):
    s[i]=s[i+1]+l[i]
ind=n
ans=[]
flag=True
for i in range(m):
    ind1=s[i+1]+1
    ind1=min(n-i-l[i]+1,ind1)
    if ind-ind1>l[i] or ind1<1:
        flag=False
        break
    ind=ind1
    ans.append(ind)
if flag==False:
    out(-1)
else:
    outl(ans)