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

qu = int(input())
for _ in range(qu if True else 1):
    n, m = map(int, input().split())
    x = []
    y = []
    di = {}
    z = []
    pairs = []
    for __ in range(m):
        a, b = map(int, input().split())
        pairs += [(b, a)]
        z += [a+b]
        if a not in di:
            di[a] = b
        else:
            di[a] = max(di[a], b)
        x += [a]
        y += [b]
    x = sorted(x, reverse=True)
    pairs = sorted(pairs, reverse=True)
    y = sorted(y)
    mv = 0
    for i in di:
        if di[i] == y[-1]:
            mv = max(mv, i)
    p, q, r = 0, 0, 0
    ans = 0
    for i in range(m):
        diff = n - q
        while r < m and diff and x[r] > pairs[i][0]:
            p,q,r = p+x[r], q+1, r+1
            diff -= 1
        if diff:
            ans = max(ans, p + min(pairs[i]) + pairs[i][0] * (diff-1))
        else:
            ans = max(ans, p)
        if n == q: break
    print(ans)
    if _ != qu-1:
        input()

