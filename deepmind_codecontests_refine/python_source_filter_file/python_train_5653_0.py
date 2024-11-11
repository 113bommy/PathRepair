import os
import sys
from io import BytesIO, IOBase
# region fastio
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline()
 
# --------------------------------------------------------------------

def RL(): return map(int, sys.stdin.readline().split())
def RLL(): return list(map(int, sys.stdin.readline().split()))
def N(): return int(input())
def print_list(l):
    print(' '.join(map(str,l)))
    
# sys.setrecursionlimit(100000)
# import random
# from functools import reduce
# from functools import lru_cache
# from heapq import *
# from collections import deque as dq
# import math
# import bisect as bs
# from collections import Counter
# from collections import defaultdict as dc 

for _ in range(N()):
    n = N()
    res = 0
    tl, pl = [], []
    for _ in range(n):
        i, j = RL()
        tl.append(i)
        pl.append(j)
    lt, nt, lp, np = 0, 0, 0, 0
    f = False
    for i in range(n):
        t, p = tl[i], pl[i]
        if t >= nt:
            if f:
                res += 1
            f = True
            lt, nt, lp, np = t, t + abs(p - np), np, p
        else:
            f = False
            if np < p < lp or np > p > lp:
                tt = abs(p - lp) + lt 
                if i == n - 1:
                    ttt = float('inf')
                else:
                    ttt = tl[i + 1]
                if t <= tt <= ttt:
                    res += 1
    if f:
        res += 1
    print(res)
