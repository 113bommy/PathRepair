# This code is written by Nikhil Tiwari
from sys import *
from math import *
from collections import *
import string
import re
from bisect import *
from functools import reduce
from itertools import permutations, combinations
# import numpy as np
# def arr(): return np.random.randint(1,50,5)
 
t=stdin.readline
R=range
p=stdout.write
mod = int(1e9)+7
MAX = 9223372036854775808
INF = float('inf')
lower = string.ascii_lowercase
upper = string.ascii_uppercase
numbers = string.digits

S = lambda : t().strip()
I = lambda : int(t())
GI = lambda: map(int, input().strip().split())
GS = lambda : map(str, t().strip().split())
IL= lambda: list(map(int, t().strip().split()))
SL = lambda : list(map(str, t().strip().split()))
mat = lambda n : [IL() for i in range(n)]
d2b = lambda n : bin(n)[2:]
ispow2 = lambda x : ((x!=0) and (x&(x-1))==0)
powof2 = lambda x : 1<<x
iSq = lambda x : (ceil(float(sqrt(x))) == floor(float(sqrt(x))))
def sieve(n): return reduce(lambda r, x: r - set(range(x**2, n, x)) if x in r else r, 
                            range(2, int(n**0.5) + 1), set(range(2,n)))
def ls(x,y): return x<<y # adding '0' y bits from right and removing last y bits from left i.e floor(x/pow(2,y)) 
def rs(x,y): return x<<y # adding '0' y bits from left and removing first y bits from right i.e x*pow(2,y) 
def BS_left(n,a,x): i=bisect_left(a,x);return [-1,i][i != n and a[i] == x] 
def BS_right(n,a,x): i=bisect_right(a,x);return [-1,i][i != n and a[i] == x] 

for _ in range(I()):
    t()
    xa,ya=GI()
    xb,yb=GI()
    xf,yf=GI()
 
    ans = abs(xa-xb) + abs(ya-yb)
    if (xa==xb==xf and ya<yf<yb or ya>yf>yb) or (ya==yb==yf and xa<xf<xb or xa>xf>xb):
        ans+=2
    print(ans)
