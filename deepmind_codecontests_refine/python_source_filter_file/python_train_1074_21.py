import os
import gc
import sys
from io import BytesIO, IOBase
from collections import Counter
from collections import deque
import heapq
import math
import statistics

def sin():
    return input()

def ain():
    return list(map(int, sin().split()))

def sain():
    return input().split()

def iin():
    return int(sin())


MAX = float('inf')
MIN = float('-inf')
MOD = 1000000007

def readTree(n, m):
    adj = [deque([]) for _ in range(n+1)]
    for _ in range(m):
        u,v = ain()
        adj[u].append(v)
        adj[v].append(u)
    return adj

def solve(d):
    xy = [MIN, MAX]
    for rt in d:
        if xy[0] > rt[1]:
            return -1
        if xy[1] < rt[0]:
            return -1
        xy[0] = max(xy[0], rt[0])
        xy[1] = min(xy[1], rt[1])
    # print(xy)
    return xy


def main():
    n = iin()
    a = ain()
    a.sort(reverse=True)
    i = 0
    area = 0
    if n > 1:
        while i < n-1:
            area = math.pi * (a[i]**2 - a[i+1]**2)
            i += 2
    if n & 1 == 1:
        area += (math.pi*a[-1]*a[-1])
    print('%.10f'%area)













        
        
        


    












# Fast IO Template starts

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

# Fast IO Template ends

if __name__ == "__main__":
    main()
