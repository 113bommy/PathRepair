# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 19/07/2020

from sys import stdin,stdout
from math import gcd, ceil, sqrt
from collections import Counter
from bisect import bisect_left, bisect_right
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

def solve(l, r, m):
    for i in range(l, r + 1):
        if m % i == 0:
            return [l, l, i]
        else:
            need = m % i
            if r - l >= need and m - need > 0:
                return [i, r, r - need]
            elif i - need <= r - l:
                return [i, r - (i - need), r]

tc = ii1()
for _ in range(tc):
    l, r, m = iia()
    if l != r:
        print(*solve(l, r, m))
    else:
        print(l, l, l)
