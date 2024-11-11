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

def calc(a, v):
    mxx = -1
    ans = 0
    for i in range(len(a)):
        if mxx == -1:mxx = a[i]
        ans += max(mxx, a[i]) - a[i]
        mxx = max(mxx, a[i])
        a[i] = mxx
    #print(ans, a)
    bb = 0
    for x in sorted(list(set(a)), reverse=True):
        ans += v - bb - x
        bb = v - x
    return ans

def find(s):
    start = 0
    n = len(s)
    if s[0] == s[-1]:
        start = n-1
        while start > 0 and s[start-1] == s[start]:
            start -= 1
    s += s
    cur = s[start]
    val = 0
    a=[]
    for i in range(start, start+n):
        if s[i] == cur:
            val += 1
        else:
            cur = s[i]
            a += [val]
            val = 1
    a += [val]
    #print(a,start)
    ans = 0
    for i in a:
        ans += i // 3 if i != n else (i+2)//3
    return ans

for _ in range(int(input()) if True else 1):
    n = int(input())
    #a, b = map(int, input().split())
    #c, d = map(int, input().split())
    s = input()
    print(find(s))