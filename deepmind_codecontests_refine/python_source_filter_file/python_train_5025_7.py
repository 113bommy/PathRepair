# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase

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
input = lambda: sys.stdin.readline().rstrip("\r\n")

# ------------------- fast io --------------------
from math import gcd, ceil

def pre(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


def prod(a):
    ans = 1
    for each in a:
        ans = (ans * each)
    return ans

def lcm(a, b): return a * b // gcd(a, b)


def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y
from collections import deque

def bfs(graph, alpha=0):
    """Breadth first search on a graph!"""
    n = len(graph)
    q = deque([alpha])
    used = [False]*n
    used[alpha] = True
    dist, parents = [0]*n, [-1]*n
    while q:
        v = q.popleft()
        for u in graph[v]:
            if not used[u]:
                used[u] = True
                q.append(u)
                dist[u] = dist[v] + 1
                parents[u] = v
    return used, dist, parents

def shortest_path(graph, alpha, omega):
    """Returns the shortest path between two vertices!"""
    used, dist, parents = bfs(graph, alpha)
    if not used[omega]:
        return []
    path = [omega]
    v = omega
    while parents[v] != -1:
        path += [parents[v]]
        v = parents[v]
    return path[::-1]


for _ in range(int(input()) if True else 1):
    n, a, b, da, db = map(int, input().split())
    graph = [[] for __ in range(n+1)]
    for i in range(n-1):
        x, y = map(int, input().split())
        graph[x] += [y]
        graph[y] += [x]

    u, d, p = bfs(graph, 1)
    ma = max(d)
    for i in range(len(d)):
        if d[i] == ma:break
    u, d, p = bfs(graph, i)
    di = max(d)
    u, d, p = bfs(graph, a)
    dist = d[b]
    #print(di, dist)
    print("Alice"if dist <= da or min(2*da, di) >= min(2*db, di)else"Bob")




