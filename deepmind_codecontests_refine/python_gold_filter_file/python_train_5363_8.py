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
n,p,q=RI()
s=RS()[0]
for i in range(n//p + 1):
    if (n-i*p)%q==0:
        print(i+(n-i*p)//q)
        for j in range(0,i*p,p):
            print(s[j:j+p])
        for j in range((i*p),n,q):
            print(s[j:j+q])
        exit(0)
print(-1)

