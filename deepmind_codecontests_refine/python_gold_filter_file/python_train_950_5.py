import os
import sys
from io import BytesIO, IOBase
import heapq as h 
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
import math, string
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
It would appear to be enough to count the number of good pairs. Once we have this number, we can place the good pair in any of 2*(K-1) positions, and for each
of these we have N**(K-2) choices
Does this create conflicts? Yes. Damn.
Is it easier to count only red sequences? Probably
The total number of sequences is N**K
Now we need to find the number of connected components with only red edges, and consider any nodes not in this list as isolated.
Answer is therefore N**K - sum_i(L_i**K) where L_i is the number of nodes in the ith red-connected component
"""
M = 10**9 + 7

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

def solve():
    N, K = getInts()
    graph = col.defaultdict(set)
    nodes = set([j+1 for j in range(N)])
    for n in range(N-1):
        U, V, X = getInts()
        if not X:
            graph[U].add(V)
            graph[V].add(U)
    ans = pow(N,K,M)
    @bootstrap
    def dfs(node):
        if node in nodes:
            nodes.remove(node)
            visited.append(node)
        for neighbour in graph[node]:
            if neighbour in nodes:
                yield dfs(neighbour)
        yield
    
    while nodes:
        node = next(iter(nodes))
        visited = []
        dfs(node)
        ans -= pow(len(visited),K,M)
    
    return ans % M

#for _ in range(getInt()):    
print(solve())
