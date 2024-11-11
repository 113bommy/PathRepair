from sys import setrecursionlimit, exit, stdin
from math import ceil, floor, acos, pi
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
from functools import reduce
import itertools
setrecursionlimit(10**7)
RI=lambda x=' ': list(map(int,input().split(x)))
RS=lambda x=' ': input().rstrip().split(x)
dX= [-1, 1, 0, 0,-1, 1,-1, 1]
dY= [ 0, 0,-1, 1, 1,-1,-1, 1]
mod=int(1e9+7)
eps=1e-6
MAX=1000
#################################################
taken=[0]*101
n=RI()[0]
l1, r1 = RI()
for i in range(1, n):
    l, r = RI()
    for j in range(l, r):
        taken[j]=1
ans=0
for i in range(l1, r1+1):
    if not taken[i]:
        ans+=1
print(ans)


    
