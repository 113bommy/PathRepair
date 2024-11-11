# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 26/04/2020

from sys import stdin,stdout
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

tc = ii1()
for _ in range(tc):
    x, y = iia()
    a, b = iia()
    res = float("inf")
    res = min(res, x * a + y * b)
    m = min(x, y)
    res = min(res, ((max(x, y) - m) * a) + (m * b))
    print(res)
    
