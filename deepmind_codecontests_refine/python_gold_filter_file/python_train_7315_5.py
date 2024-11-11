#!/usr/bin/env python3
 
import sys
import math
mod = 10**9 + 7
inf = float('inf')
from collections import defaultdict
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
 
class BinaryIndexedTree:
    def __init__(self, size):
        self.bit = [0 for _ in range(size)]
        self.size = size
 
    def add(self, i, w):
        x = i + 1
        while x <= self.size:
            self.bit[x - 1] += w
            x += x & -x
        return
 
    def sum(self, i):
        res = 0
        x = i + 1
        while x > 0:
            res += self.bit[x - 1]
            x -= x & -x
        return res
 
    
t = I()
for _ in range(t):
    n = I()
    a = LI()
    b = sorted(a)
    d = defaultdict(int)
    for i in range(n):
        d[b[i]] = i
    BIT = BinaryIndexedTree(n+1)
    cnt = 0
    for i, ai in enumerate(a):
        BIT.add(d[ai], 1)
        cnt += i+1 - BIT.sum(d[ai])
    if cnt > n*(n-1) // 2 - 1:
        print('NO')
    else:
        print('YES')