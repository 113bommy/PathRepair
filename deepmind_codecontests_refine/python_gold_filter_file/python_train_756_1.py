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
def S(): return input().strip()
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

n = N()
sn = set(range(n))
p = [tuple(RL()) for _ in range(n)]
S = sum(v[1] for v in p)
dic = [(0, set()) for _ in range(10001)]
res = []
k = 0
while k < n:
    for j in range(k * 100, -1, -1):
        if len(dic[j][1]) != k: continue
        vj, sj = dic[j][0], dic[j][1]
        for i in sn ^ sj:
            if dic[j + p[i][0]][0] <= p[i][1] + vj:
                dic[j + p[i][0]] = (p[i][1] + vj, sj | {i})
    k += 1
    m, t = 0, -1
    for j in range(k * 100, 0, -1):
        if len(dic[j][1]) != k: continue 
        if dic[j][0] <= t:
            dic[j] = (0, set())
        else:
            t = dic[j][0]   
            m = max(m, min(j, (S + t) / 2))
    res.append(m)
print(*res)
