import os
import sys
from io import BytesIO, IOBase
 
from types import GeneratorType
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
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
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
import time
start_time = time.time()

import collections as col
import math
from functools import reduce

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())



"""
dp approach?

how many of the first i points can we visit?
dp[i] = most points finishing at point i = max(dp[i-something]+1 if i reachable directly from something)
dp[1] = dp[0] + 1 if 1 reachable from 0
dp[2] = max(dp[0] + 2 reachable from 0,dp[1] + 1 reachable from 0)

-----
Max number finishing at point i
dp[i] = max(dp[j] + 1) for 0 <= j < i where dist(i,j) <= ti - tj and point[0] = [1,1]
Max manhattan distance is 998
So in 998 seconds we can reach anyone
dp[i] is at least dp[i-998]+1
"""

def solve():
    R, N = getInts()
    dp = [-1000]*(N+1)
    A = [(0,1,1)]+[tuple(getInts()) for i in range(N)]
    max_dp = [0]*(N+1)
    M = 2*R
    dp[0] = 0
    for i in range(1,N+1):
        t,x,y = A[i]
        best = 0
        if i >= M: dp[i] = max_dp[i-M]+1
        best = dp[i]
        for j in range(i-1,max(-1,i-M),-1):
            t0, x0, y0 = A[j]
            if dp[j] >= best and abs(x-x0) + abs(y-y0) <= t-t0:
                best = dp[j]+1
        dp[i] = best
        max_dp[i] = max(max_dp[i-1],dp[i])
    return max_dp[N]
    
#for _ in range(getInt()):    
print(solve())
