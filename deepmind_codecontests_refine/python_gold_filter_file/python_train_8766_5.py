import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
#from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7

x0, y0, ax, ay, bx,  by=mdata()
xs, ys,  t=mdata()
l=[(x0,y0)]
s=[abs(xs-x0)+abs(ys-y0)]
ind=0
ans=0
while ax*l[-1][0]+bx-xs + ay*l[-1][1]+by-ys<=t:
    s.append(abs(ax*l[-1][0]+bx-xs) + abs(ay*l[-1][1]+by-ys))
    l.append((ax*l[-1][0]+bx, ay*l[-1][1]+by))
s1=[0]
for i in range(1,len(l)):
    s1.append(sum(l[i])-sum(l[i-1]))
for i in range(len(s)):
    for j in range(i,len(s)):
        for k in range(j,len(s)):
            sum1=sum(s1[i+1:k+1])+s[j]
            if i!=j and k!=j:
                sum1+=max(sum(s1[j+1:i+1]),sum(s1[i+1:k+1]))
            if sum1<=t:
                ans=max(ans,k-i+1)
out(ans)
