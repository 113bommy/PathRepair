import os
import sys
from io import BytesIO, IOBase
from math import ceil, floor, pow, sqrt, gcd
from collections import Counter, defaultdict
from itertools import permutations, combinations
from time import time, sleep

BUFSIZE = 8192
MOD = 1000000007

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


stdin, stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
from os import path
if path.exists('tc.txt'):
    stdin = open('tc.txt', 'r')
def gmi(): return map(int, stdin.readline().strip().split())
def gms(): return map(str, stdin.readline().strip().split())
def gari(): return list(map(int, stdin.readline().strip().split()))
def gart(): return tuple(map(int, stdin.readline().strip().split()))
def gars(): return list(map(str, stdin.readline().strip().split()))
def gs(): return stdin.readline().strip()
def gls(): return list(stdin.readline().strip())
def gi(): return int(stdin.readline())
def pri(i, end="\n"): stdout.write(f"{i}" + end)
def priar(ar, end="\n"): stdout.write(" ".join(map(str, ar)) + end)


def solve():
    n = gi()
    ar = gari()
    mp = dict([(ar[i], i+1) for i in range(n)])
    mx = max(ar)
    ans = 0

    for i in range(n-1):
        for j in range(1, mx//ar[i]+1):
            if j in mp and mp[j]+i+1 == ar[i]*j and i+1<mp[j]:
                ans += 1

    return ans

if __name__ == "__main__":
    tc = gi()
    for i in range(tc):
        pri(solve())
