#!/usr/bin/env python
from __future__ import division, print_function
import math
import os
import sys
from sys import stdin,stdout
from io import BytesIO, IOBase
from collections import deque
#sys.setrecursionlimit(10**5)
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip


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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
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

# endregion
"""
def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int,input().split()))
        arr = sorted(arr)
        for i in range(len(arr)-1,-1,-1):
            if arr[i]<=i+1:
                print(i+2)
                break
        else:
            print(1)
"""
"""
def main():
    n,a,b = map(int,input().split())
    if a+b<n:
        print(b+1)
    else:
        print(n-a)
"""
"""
def main(n):
    s1_0 = int(math.ceil(n ** (1 / 3.0)))
    minSA = -1
    s1 = s1_0
    while s1 >= 1:
        while n % s1 > 0:
            s1 = s1 - 1
        s1quot = int(n / s1)
        s2_0 = int(math.ceil(math.sqrt(n / s1)))
        s2 = s2_0
        while s2 >= 1:
            while s1quot % s2 > 0:
                s2 = s2 - 1
            s3 = int(n / (s1 * s2))
            SA = 2 * (s1 * s2 + s1 * s3 + s2 * s3)
            if minSA == -1:
                minSA = SA
            else:
                if SA < minSA:
                    minSA = SA
            s2 = s2 - 1
        s1 = s1 - 1
    return minSA
"""
"""
def main():
    t = int(input())
    for _ in range(t):
        a,b,x,y,n = map(int,input().split())
        g=a
        h=b
        c = n
        min1=0
        min2=0
        a-=min(a-x,n)
        n-=min(g-x,n)
        b-=min(b-y,n)
        min1=a*b
        a = g
        b = h
        t = a
        f = b
        n= c
        b-=min(b-y,n)
        n-=min(f-y,n)
        a-=min(a-x,n)
        min2=a*b
       # print(min1,min2)
        print(min(min1,min2))
"""
def main():
    l=[]
    p=[]
    g=[]
    c=0
    for i in range(3):
        arr = list(map(int,input().split()))
        p.append(arr)
        for i in arr:
            g.append(i)
        sum1 = sum(arr)
        l.append(sum1)
   # print(l)
    max1 = max(l)
    for i in range(max1,max1+10**5+3):
        if (i-l[0])+(i-l[1])+(i-l[2])==i:
            c =i
           # print(c)
            break
   # print(c)
    p[0][0] = c - l[0]
    p[1][1] = c - l[1]
    p[2][2] = c - l[2]
    for i in range(len(p)):
        for j in range(len(p)):
            print(p[i][j],end=" ")
        print()

if __name__ == '__main__':
    main()