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
For each leaf, traverse upwards through the tree until we reach a visited node. If we encounter a problem road, include that.
"""

def solve():
    N = getInt()
    graph, prob = dd(set), dd(int)
    for n in range(N-1):
        A, B, T = getInts()
        graph[A].add(B)
        graph[B].add(A)
        if A > B:
            A, B = B, A
        prob[(A,B)] = T
    probs = []
    prob_set = set()
    def bfs(node):
        queue = dq([(node,0)])
        visited.add(node)
        parent[node] = 0
        while queue:
            node, level = queue.popleft()
            count = 0
            for neighbour in graph[node]:
                if neighbour not in visited:
                    queue.append((neighbour,level+1))
                    visited.add(neighbour)
                    parent[neighbour] = node
                    count += 1
                    if prob[(min(node,neighbour),max(node,neighbour))] == 2:
                        probs.append((level,node,neighbour))
                        prob_set.add((node,neighbour))
            if not count:
                leaf.append(node)
    #need to assign levels to the problem edges
    parent = dd(int)
    leaf = []
    visited = set()
    bfs(1)
    visited = set()
    ans = []
    probs.sort()
    while probs:
        level, par, child = probs.pop()
        if (par,child) not in prob_set:
            break
        prob_set.remove((par,child))
        ans.append(child)
        visited.add(child)
        child = par
        while True:
            visited.add(child)
            par = parent[child]
            if not par: break
            if (par,child) in prob_set: prob_set.remove((par,child))
            if par in visited: break
            child = par
    print(len(ans))
    print(*ans)
    return
    
#for _ in range(getInt()):
solve()