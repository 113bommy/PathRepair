# template begins
#####################################
from io import BytesIO, IOBase
import sys
import math
import os
import heapq
from collections import defaultdict, deque
from math import ceil
from bisect import bisect_left, bisect_left
from time import perf_counter


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
def input(): return sys.stdin.readline().rstrip("\r\n")
def mint(): return map(int, input().split())
def mfloat(): return map(float, input().split())
def intin(): return int(input())


#####################################
# template ends
# Use the recursion snippet if heavy recursion is needed (depth>1000)
# If constraints are tight, use 1d arrays instead of 2d, like g[i*m+j] instead of g[i][j]
class Cave:
    def __init__(self, arr):
        self.n, *self.a = arr
        self.needed = self.a[0]+1
        for i in range(self.n):
            self.needed = max(self.needed, self.a[i]-i+1)


def solve():
    n = int(input())
    caves = [Cave(map(int, input().split())) for i in range(n)]
    caves.sort(key=lambda c: c.needed)
    start = 0
    boost = 0
    for i in caves:
        if i.needed > boost+start:
            start += i.needed - boost - start
            boost += i.n
    print(start)


def main():
    t = 1
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    start_time = perf_counter()
    main()
    print(perf_counter()-start_time, file=sys.stderr)
