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

for _ in range(int(input()) if not True else 1):
    n = int(input())
    #n, k = map(int, input().split())
    #n, m = map(int, input().split())
    #c, d = map(int, input().split())
    a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    #s = input()
    cur_row = 0
    ans = []
    cols = [[] for i in range(n+1)]
    two = []
    three = []
    for i in range(n):
        if a[i] == 0:
            continue
        if a[i] == 2:
            if three:
                cols[i] += [three.pop()]
            two += [cur_row]
            cols[i] += [cur_row]
            cur_row += 1
        if a[i] == 3:
            if not three:
                three += [cur_row]
                cols[i] += [cur_row]
            else:
                cols[i] += [three.pop()]
                cols[i] += [cur_row]
                three += [cur_row]
            cur_row += 1
        if a[i] == 1:
            if three:
                cols[i] += [three.pop()]
                cols[i] += [cur_row]
                cur_row += 1
            elif two:
                cols[i] += [two.pop()]
            else:
                cols[i] += [cur_row]
                cur_row += 1
    x = [k for p in cols for k in p]
    if not x:
        print(0)
        continue
    if (max(x) >= n or two or three):
        print(-1)
    else:
        for i in range(n):
            for j in cols[i]:
                ans += [[i+1, j+1]]
        print(len(ans))
        for i in ans:
            print(*i)




