from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())

n,p=mdata()
s=data()
p=min(p-1,n-p)
ind1=p
ind2=p
k=0
for i in range(n//2):
    t=abs(ord(s[i])-ord(s[n-1-i]))
    if t!=0:
        k+=min(t,26-t)
        if i<ind2:
            ind2=i
        elif i>ind1:
            ind1=i
k+=2*min(ind1-p,p-ind2)+max(ind1-p,p-ind2)
print(k)