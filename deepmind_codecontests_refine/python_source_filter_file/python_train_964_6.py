import os
import sys
from io import BytesIO, IOBase
import math
from itertools import permutations
from decimal import *

getcontext().prec = 25
MOD = pow(10, 9) + 7
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

# n, k = map(int, input().split(" "))
# l = list(map(int, input().split(" ")))

for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    l = input()
    if n == k:
        print(2 * k - 1)
    else:
        t = 0
        z = []
        w = L = False
        le = pre = 0
        for i in range(n):
            if l[i] == "L":
                L = True
                pre += 1
            else:
                break
        start = max(1, pre)
        if l[0]=="W":
            t+=1
        for i in range(start, n):
            if l[i] == "W":
                w=True
                if le:
                    z.append(le)
                    le = 0
                if l[i - 1] == "W":
                    t += 2
                else:
                    t += 1
            if l[i] == "L":
                L = True
                le += 1
        extra = le
        z.sort()
        if k == 0 or not L:
            print(t)
        elif not extra and not z:
            if not w:
                print(2*(min(pre,k) -1))
            else:
                print(2*(min(pre,k))+t)
        elif not z:
            t += 2 * (min(pre, k))
            k = max(0, k - pre)
            t += 2 * (min(k, extra))
            print(t)
        elif z:
            for i in range(len(z)):
                if z[i] <= k:
                    k -= z[i]
                    t += 2 * z[i] + 1
                else:
                    t += 2 * k
                    k = 0
                    break
            if k:
                t += 2 * (min(pre, k))
                k = max(0, k - pre)
                t += 2 * (min(k, extra))
            print(t)
