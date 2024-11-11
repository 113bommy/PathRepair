from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
#sys.setrecursionlimit(100000)

s1=data()
s2=data()
l1=len(s1)
l2=len(s2)
ans=ind=0
for i in range(min(l1,l2)):
    if l1%(i+1)==0 and l2%(i+1)==0:
        if s1[:i+1]*(l1//(i+1))==s1 and s2[:i+1]*(l2//(i+1))==s2:
            ans=1
            ind=i
            break
if ans==0:
    print(0)
else:
    g=gcd(l1//(ind+1),l2//(ind+1))
    if g>1:
        ans+=1
    for i in range(2,int(g**0.5)+1):
        if g%i==0:
            ans+=1
            if g//i!=i:
                ans+=1
    print(ans)