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

from collections import deque

for _ in range(int(input()) if not True else 1):
    #n = int(input())
    #n, k = map(int, input().split())
    #a, b = map(int, input().split())
    #c, d = map(int, input().split())
    #a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    s1 = deque(k for k in input())
    s2 = deque(k for k in input())
    n = len(s1)
    k = int(input())
    if k == 0:
        print(int(s1==s2))
        quit()
    mod = 10**9 + 7
    n1pow = [1]
    for i in range(696969):
        n1pow += [(n1pow[-1]*(n-1)) % mod]
    ans0 = 0
    for i in range(2, k+1):
        ans0 = (n1pow[i] - ans0) % mod
    ans1 = 1
    for i in range(1, k):
        ans1 = (n1pow[i] - ans1) % mod
    #print(ans0, ans1)
    total = 0
    for t in range(n):
        if s1 == s2:
            total += ans1 if t else ans0
        s1.appendleft(s1.pop())
    print(total % mod)