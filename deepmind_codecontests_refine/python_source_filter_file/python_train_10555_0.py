"""
#If FastIO not needed, used this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left, bisect_right

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

from collections import defaultdict as dd, deque as dq
import math, string

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

MOD = 10**9+7

"""
min cost to fix 1 hole is the min cost of any segment
min cost to fix 2 holes is the min cost of all segments length >= 2, or the min cost of two distinct segments length 1
min cost to fix K holes is the min cost of all segments length >= K, or the min cost of fixing K-1 segments + the min cost of any other segment 

What is the cost of filling interval [L,R]? 
"""

from bisect import bisect_left

def solve():
    N, M, K = getInts()
    costs = []
    cost = [[float('inf') for R in range(N+1)] for L in range(N+1)]
    for m in range(M):
        L, R, C = getInts()
        L -= 1
        costs.append((L,R,C))
        cost[L][R] = min(cost[L][R], C)
    for L in range(N+1):
        for R in range(1,N+1):
            cost[R][L] = min(cost[R][L], cost[R-1][L])
    dp = [[10**18 for R in range(N+1)] for L in range(N+1)]
    #print(cost)
    for i in range(N):
        dp[i][0] = 0
        for j in range(i+1):
            if dp[i][j] < 10**10:
                dp[i+1][j] = min(dp[i+1][j], dp[i][j])
                for k in range(i+1,N+1):
                    dp[k][j+k-i] = min(dp[k][j+k-i],dp[i][j]+cost[i][k])
    ans = 10**18
    #print(dp)
    ans = dp[N][K]
            
    return ans if ans < 10**18 else -1
    
#for _ in range(getInt()):
print(solve())
    #solve()