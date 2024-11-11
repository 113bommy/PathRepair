###############################
# https://codeforces.com/contest/1010/problem/A
# 2021/01/12
# WenhuZhang
################################
from sys import stdin
import collections
import copy
import math


n = int(stdin.readline())
m = int(stdin.readline())
up = list(map(int, stdin.readline().split()))
down = list(map(int, stdin.readline().split()))

def check(x):
    weight = m + x
    fuel = x
    for i in range(n):
        f = weight/up[i]
        if fuel<f:
            return False
        else:
            weight -= f
            fuel -= f
        f = weight/down[i]
        if fuel<f:
            return False
        else:
            weight -= f
            fuel -= f
    return True


l = 0
r = 1e9 + 1e-6

for ii in range(100):
    mid = (r + l)/2
    # print(mid)
    if(check(mid)):
        r = mid
    else:
        l = mid
    if r-l <= 1e-10:
        break
if l >= 1e9+ 1e-6:
    print(-1)
else:
    print("%.10f" %l)

