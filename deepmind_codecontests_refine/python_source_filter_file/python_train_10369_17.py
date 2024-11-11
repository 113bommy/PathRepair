import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left,bisect
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
x,y,l,r=map(int,input().split())
p=[i for i in range(61)]
q=[i for i in range(61)]
t=set()
c=0
if r==1:
    print(1)
else:
    a=math.ceil(math.log(r-1,x))
    b=math.ceil(math.log(r-1,y))
    print(a,b)
    for i in range(a+1):
        for j in range(b+1):
            s=x**p[i]+y**q[j]
            if s>=l and s<=r:
                t.add(s)
    t=list(sorted(t))
    c=len(t)
    print(t)
    if c>0:
        m=t[0]-l
        for i in range(c-1):
            m=max(m,t[i+1]-t[i]-1)
        m=max(m,r-t[-1])
    else:
        m=r-l+1
    print(m)
    