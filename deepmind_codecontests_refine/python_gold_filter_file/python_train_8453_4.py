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

for _ in range(int(input()) if True else 1):
    #n = int(input())
    n, m = map(int, input().split())
    #a, b = map(int, input().split())
    #c, d = map(int, input().split())
    #a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    #s = input()
    a = []
    for i in range(n):
        a += [[k for k in input()]]
    pos = False
    has = False
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'A':
                pos=True
            else:
                has = True
    if not pos:
        print("MORTAL")
        continue
    if not has:
        print(0)
        continue
    first_row = a[0]
    last_row = a[-1]
    first_col = [a[k][0] for k in range(n)]
    last_col = [a[k][-1] for k in range(n)]

    if first_row == ['A'] * m or last_row == ['A']*m or first_col == ['A']*n or last_col == ['A']*n:
        print(1)
        continue

    pos = False
    for i in a:
        if i == ['A']*m:
            pos=True
            break
    for j in range(m):
        if [a[i][j] for i in range(n)] == ['A']*n:
            pos = True
            break

    if 'A' in [a[0][0], a[0][-1], a[-1][0], a[-1][-1]] or min(n,m) == 1 or pos:
        print(2)
        continue

    if 'A' in first_row+first_col+last_col+last_row:
        print(3)
        continue

    print(4)