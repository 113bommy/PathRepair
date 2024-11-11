# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
from io import BytesIO, IOBase
import sys
from collections import defaultdict, deque, Counter
from math import sqrt, pi, ceil, log, inf, gcd, floor
from itertools import combinations, permutations
from bisect import *
from fractions import Fraction
from heapq import *
from random import randint

mod = 1000000007

def main():
    n=int(input())
    a=[]
    for i in range(2*n):
        a.append(input().split())
    b,c,f=[],[],0
    heapify(c)
    for i in range(2*n-1,-1,-1):
        if len(a[i])==2:
            a[i][1]=int(a[i][1])
            heappush(c,a[i][1])
        else:
            if c==[]:
                f=1
                break
            b.append(heappop(c))
    if f:
        b.reverse()
        j=0
        d=[]
        for i in range(2*n):
            if len(a[i])==1:
                d.append(b[j])
                j+=1
            else:
                if d==[] or d[-1]!=a[i][1]:
                    f=0
                    break
                d.pop()
        if f:
            print("YES")
            print(*b)
        else:
            print("NO")
    else:
        print("NO")


    
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