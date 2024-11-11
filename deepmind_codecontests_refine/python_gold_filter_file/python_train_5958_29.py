from math import factorial, ceil
from collections import Counter
from heapq import heapify, heappop, heappush
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
input = lambda: sys.stdin.readline().rstrip("\r\n")

# ------------------------------

def RL(): return map(int, sys.stdin.readline().rstrip().split())
def comb(n, m): return factorial(n) / (factorial(m) * factorial(n - m)) if n >= m else 0
def perm(n, m): return factorial(n) // (factorial(n - m)) if n >= m else 0
def mdis(x1, y1, x2, y2): return abs(x1 - x2) + abs(y1 - y2)
inputI = int(input())
mod = 1000000007
INF = float('inf')

# ------------------------------
def main():
    N = inputI
    for _ in range(N):
        n, g, b = RL()
        need = ceil(n/2)
        t = ceil(need/g)
        # print(need%g, "+++", )
        res = t*g + (t-1)*b - (t*g-need)
        # print(res, need)
        print(max(res, n))

if __name__ == "__main__":
    main()