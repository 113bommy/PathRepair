import math
import os
import sys
from io import BytesIO, IOBase
M = 1000000007
import random
import heapq
import bisect
import time
from functools import lru_cache
from collections import *
from itertools import *
#sys.setrecursionlimit(1<<30)
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
def print(*args, **kwargs):
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
def inp(): return sys.stdin.readline().rstrip("\r\n")  # for fast input
def out(var): sys.stdout.write(str(var))  # for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def fsep(): return map(float, inp().split())
def inpu(): return int(inp())
"""
dp = [1] * (1000001)
dp2 = [1] * (1000001)
def dfs(dc, cur, p):
    dp[cur] = 0
    dp2[cur] = 0
    for nbr in dc[cur]:
        if nbr == p:
            continue
        dfs(dc, nbr, cur)
        dp[cur] = max(1 + dp2[cur] + dp2[nbr], dp[cur] + dp[nbr])
        dp2[cur] = dp[nbr] + dp2[cur]
def main():
    n = inpu()
    dc = defaultdict(list)
    for i in range(1, n):
        a, b = sep()
        dc[a].append(b)
        dc[b].append(a)
    dfs(dc, 1, -1)
    print(max(dp[1], dp2[1]))
if __name__ == '__main__':
    main()
"""
def main():
    t=1
    t=inpu()
    for _ in range(t):
        a,b=sep()
        if a==0 and b==0:
            print(0)
            continue
        if a==b:
            print(1)
            continue
        if abs(a-b)==1:
            print(-1)
            continue
        else:
            print(2)
if __name__ == '__main__':
    main()
