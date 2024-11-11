# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 03/07/2020

from sys import stdin, stdout
from collections import Counter
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

n = ii1()
arr = set(iia())
res = 1
sel = set([next(iter(arr))])
for i in arr:
    for j in range(30):
        ele = set([i])
        if i + 2 ** j in arr:
            ele.add(i + 2 ** j)
        if i - 2 ** j in arr:
            ele.add(i - 2 ** j)
        if len(ele) > res:
            res = len(ele)
            sel = ele

print(res)
print(*sel)   

