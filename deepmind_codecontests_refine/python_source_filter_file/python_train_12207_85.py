# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 20/06/2020

from sys import stdin,stdout
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

tc = ii1()
for _ in range(tc):
    res = 1
    n = ii1()
    for i in range(1, n + 1):
        if i + 2 <= n:
            res = max(res, gcd(i, i + 2))
    print(res)