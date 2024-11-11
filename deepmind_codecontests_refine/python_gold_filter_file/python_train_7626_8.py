# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 04/09/2020
from sys import stdin, stdout, setrecursionlimit
import heapq
from math import gcd, ceil, sqrt
from collections import Counter, deque
from bisect import bisect_left, bisect_right
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
setrecursionlimit(100000)
mod = 1000000007

tc = ii1()
for _ in range(tc):
    my, frnd = iia()
    swrd, axe = iia()
    wtswrd, wtaxe = iia()
    if wtswrd > wtaxe:
        wtswrd, wtaxe = wtaxe, wtswrd
        swrd, axe = axe, swrd
    res = 0
    for i in range(swrd + 1):
        if i * wtswrd > my:
            break
        sw1 = i
        ax1 = min((my - (sw1 * wtswrd)) // wtaxe, axe)
        sw2 = min(swrd - i, frnd // wtswrd)
        ax2 = min((frnd - (sw2 * wtswrd)) // wtaxe, axe - ax1)
        res = max(res, sw1 + sw2 + ax1 + ax2)
    print(res)
        
        

        
    