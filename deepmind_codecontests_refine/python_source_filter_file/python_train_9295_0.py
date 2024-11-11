# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
from io import BytesIO, IOBase
import sys
from collections import defaultdict, deque, Counter
from math import sqrt, pi, ceil, log, inf, gcd, floor
from itertools import combinations,permutations
from bisect import *
from fractions import Fraction

def main():
    for _ in range(int(input())):
        n, m = map(int, input().split())
        a = list(map(int, input().split()))
        b=[[] for i in range(n)]
        d=sorted(a)
        for i in range(m):
            x,y= map(float,input().split())
            b[int(x)-1].append(y)
        ind=-1
        for i in range(n-1,-1,-1):
            if d[i]!=a[i]:
                ind=i
                break
        if ind==-1:
            print(0)
        else:
            ans=1
            for i in range(ind,n,1):
                for j in range(len(b[i])):
                    ans*=(1-b[i][j])
            print(1-ans)

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

if __name__ == "__main__":
    main()