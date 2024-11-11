import time
from ast import Try
from io import BytesIO, IOBase
import math
import sys
import os
from math import gcd, floor, sqrt, log
input: lambda: sys.stdin.readline().rstrip()
start_time = time.time()
def iin(): return int(input())
def sin(): return input().strip()
def listin(): return list(map(int, input().strip().split()))
def liststr(): return list(map(str, input().strip().split()))
def ceill(x): return int(x) if(x == int(x)) else int(x)+1
def ceilldiv(x, d): return x//d if(x % d == 0) else x//d+1
def LCM(a, b): return (a*b)//gcd(a, b)


def solve():
    n = iin()
    k = n // 3
    l = k
    if n % 3 == 1:
        k += 1
    elif k % 3 == 2:
        l += 2
    print(k, l)


ttt = 1
ttt = iin()
for hula in range(ttt):
    solve()


# sys.stderr.write(str(time.time()-start_time))
