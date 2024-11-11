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

def prod(a, mod=10**9+7):
    ans = 1
    for each in a:
        ans = (ans * each) % mod
    return ans

def lcm(a, b): return a * b // gcd(a, b)

def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y

def dfs(graph, alpha):
    """Depth First Search on a graph!"""
    n = len(graph)
    visited = [False]*n
    finished = [False]*n
    parents = [-1]*n
    stack = [alpha]
    dp = [0]*n
    while stack:
        v = stack[-1]
        if not visited[v]:
            visited[v] = True
            for u in graph[v]:
                if parents[u] == -1:
                    parents[u] = v
                if not visited[u]:
                    stack.append(u)
        else:
            stack.pop()
            dp[v] += 1
            for u in graph[v]:
                if finished[u]:
                    dp[v] += dp[u]
            finished[v] = True
    return visited, dp, parents

for _ in range(int(input()) if True else 1):
    n = int(input())
    #n, k = map(int, input().split())
    #a, b = map(int, input().split())
    #c, d = map(int, input().split())
    #a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    #s = input()
    n *= 2
    graph = [[] for i in range(n+1)]
    edges = {}
    for i in range(n-1):
        x, y, k = map(int, input().split())
        graph[x] += [y]
        graph[y] += [x]
        edges[(x,y)] = edges[(y,x)] = k

    visited, dp, parents = dfs(graph, 1)
    mi, ma = 0, 0
    for i in range(2, n+1):
        mi += (dp[i] % 2) * edges[(i, parents[i])]
        ma += min(dp[i], n-dp[i]) * edges[(i, parents[i])]
    print(mi, ma)