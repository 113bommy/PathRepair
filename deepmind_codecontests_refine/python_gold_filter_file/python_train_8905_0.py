import sys
from math import *
from fractions import gcd
readints=lambda:map(int, input().strip('\n').split())


n=int(input())
prev=2
for i in range(1,n+1):
    nxt = (i*(i+1))**2
    cur = (nxt-prev)//i
    print(cur)
    prev=int(sqrt(nxt))

