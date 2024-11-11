#*******************************************
#* CODER       : ANIRBAN DEY               *
#* NICK        : nonstop-baban(since 2001) *
#* INSTITUTION : IIEST, SHIBPUR(2019-2023) *
#*******************************************
import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
from collections import defaultdict
import threading

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

#------------------------------main code------------------------------------------#
t=int(input())
while t!=0:
    t-=1
    skip_points=0
    z=0
    n=int(input())
    a=list(map(int,input().split()))
    x=[]
    for i in range(0,n-1):
        if(a[i]==a[i+1]): z+=1
        else:
            if(a[i]==1):
                x.append(z+1)
                z=0
    if(a[n-1]==1):
        x.append(z+1)
    if(a[0]==1):
        skip_points=1
        x[0]-=1
    for item in x:
        skip_points+=(item//3)
    print(skip_points)
    

    