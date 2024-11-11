from functools import reduce
from operator import *
from math import *
from sys import *
from string import *
from collections import *
setrecursionlimit(10**7)
dX= [-1, 1, 0, 0,-1, 1,-1, 1]
dY= [ 0, 0,-1, 1, 1,-1,-1, 1]
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
n=RI()[0]
r=10**9
l=-r
inv={"<=":">", ">=":"<", "<":">=", ">":"<="}
for i in range(n):
    sign, x, a= RS()
    x=int(x)
    if a=='N':
        sign=inv[sign]
    if sign=="<=":
        r=min(x,r)
    elif sign==">=":
        l=max(x,l)
    elif sign=="<":
        r=min(x-1,r)
    else:
        l=max(x+1,l)
print("Impossible" if l>r else l)
