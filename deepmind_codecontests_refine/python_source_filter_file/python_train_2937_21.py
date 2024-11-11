#!/usr/bin/env python
import os
import sys
import bisect
from math import gcd,ceil
from heapq import heapify,heappop,heappush
from io import BytesIO, IOBase
 
def main():
    r,c = map(int,input().split())
    n = r+c
    nums = [i for i in range(c+1,r+c+1)][::-1]
    # print(nums)
    if r<=1 and c<=1:
        print(0)
        return
    elif r==1:
        for i in range(1,r+c+1):
            print(i,end=' ')
        print()
    else:
        a = [[0]*c for i in range(r)]
        for i in range(r):
            for j in range(c):
                if j==0:
                    a[i][j] = nums[i]
                else:
                    a[i][j] = (j+1)*a[i][0]
                print(a[i][j],end=' ')
            print()
        
    # print(a)

			
 
 
 
 
 
 
 
# region fastio
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = lambda s: self.buffer.write(s.encode()) if self.writable else None
 
    def read(self):
        if self.buffer.tell():
            return self.buffer.read().decode("ascii")
        return os.read(self._fd, os.fstat(self._fd).st_size).decode("ascii")
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline().decode("ascii")
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
def print(*args, sep=" ", end="\n", file=sys.stdout, flush=False):
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(end)
    if flush:
        file.flush()
 
 
sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
sys.setrecursionlimit(10000)
if __name__ == "__main__":
    main()