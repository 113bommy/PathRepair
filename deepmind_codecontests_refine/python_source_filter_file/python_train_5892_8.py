import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
from queue import PriorityQueue as pq
n=int(input())
l=list(map(int,input().split()))
m=sys.maxsize
s=0
p=0
c=0
t=-1*sys.maxsize
for i in l:
    if i>0:
        if i%2==1:
            c+=1
            s+=i
            m=min(m,i)
        else:
            p+=i
    else:
        if i%2==1:
            t=max(t,i)
if c>0:
    if s%2:
        print(s+p)
    else:
        print(max(s-m+p,s-t+p))
else:
    s=0
    c=0
    m=-1*sys.maxsize
    for i in l:
        if i<0:
            if i%2:
                c+=1
                m=max(m,i)
        else:
            if i%2==0:
                s+=i
    if c==0:
        print(0)
    else:
        print(s+m)
    
            