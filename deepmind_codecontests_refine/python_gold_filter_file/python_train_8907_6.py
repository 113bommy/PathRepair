from bisect import bisect_right as br
from bisect import bisect_left as bl
import math

from functools import reduce

def fac(n):
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


a,b=map(int,input().split())
f1=fac(a)
f2=fac(b)
f=list(f1 & f2)
f=list(set(f))
f.sort()

n=int(input())
for i in range(n):
    l,r=map(int,input().split())
    ans=br(f,r)
    lo=bl(f,l)
    hi=br(f,r)
    if lo==hi:
        print(-1)
    else:
        print(f[ans-1])