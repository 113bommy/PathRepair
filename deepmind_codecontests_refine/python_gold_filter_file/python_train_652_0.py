"""
#If FastIO not needed, use this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left, bisect_right
import time

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

from collections import defaultdict as dd, deque as dq, Counter as dc
import math, string

#start_time = time.time()

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

def getMat(n):
    return [getInts() for _ in range(n)]

def isInt(s):
    return '0' <= s[0] <= '9'

MOD = 10**9 + 7 

"""
Take an edge as close as possible in value to K, and build out the minimum spanning tree from that?

Delete edges greedily except for one single edge as close as possible to K

"""

def solve():
    N, M, K = getInts()
    edges = []
    for m in range(M):
        x,y,s = getInts()
        edges.append((s,x-1,y-1))
    edges.sort()
    #print(edges)
    #MST1
    def find(a):
        if a != p[a]:
            p[a] = find(p[a])
        return p[a]
        
    def union(a, b):
        a, b = find(a), find(b)
        if a == b: return
        if size[a] > size[b]:
            a, b = b, a
        p[a] = b
        size[b] += size[a]
        return
    

    p = [i for i in range(N)]
    size = [1]*N
    ans1 = 0
    best = 10**18
    best_ind = -1
    i = 0
    for s,x,y in edges:
        if find(x) != find(y):
            union(x,y)
            ans1 += max(0,s-K)
            max_used = s
        diff = abs(s-K)
        if diff < best:
            best = diff
            best_ind = i
        i += 1
    if not ans1: ans1 += abs(K-max_used)
    ans2 = best
    i = 0
    p = [i for i in range(N)]
    size = [1]*N
    s,x,y = edges[best_ind]
    union(x,y)
    for s,x,y in edges:
        if find(x) != find(y):
            union(x,y)
            ans2 += max(0,s-K)
    #print(ans1,ans2)
    return min(ans1,ans2)
    
for _ in range(getInt()):
    print(solve())
#solve()


#print(time.time()-start_time)