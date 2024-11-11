#!/usr/bin/env python
from __future__ import division, print_function
import os
import sys
from io import BytesIO, IOBase
from collections import *
from bisect import *
from string import *
from itertools import * 
from statistics import *
from math import *
from heapq import heappush as push, heappop as pop
from re import *
from functools import cmp_to_key
from queue import *
mod  = int(1e9+7)
mod1 = 998244353
imax = float("inf")
imin = float("-inf")
true = True
false= False
N    = 10**5
vowels = "aeiou"
none = None
t3bit = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
inp  = lambda : input()
I    = lambda : int(inp())
M    = lambda : map(int,inp().split())
MS   = lambda : map(str,inp().split())
S    = lambda : list(MS())
L    = lambda : list(M())
test_case_run__ = false;
def case():global test_case_run__;test_case_run__ = true;
def exit():raise SystemExit
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
#-------------------------------------------------------------------------------------------------------------------------------------

case()
def main():
    n=I()
    for i in range(n):
        print(1,end = " ")
    print()

#-------------------------------------------------------------------------------------------------------------------------------------
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while true:
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
    at_start = true
    for x in args:        
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = false
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", false):
        file.flush()
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
class maths:
    def power(self,a,b):
        #a%=m;
        res = 1;
        while b > 0:
            if(b&1):
                res = res * a #% m;
            a = a * a #% m;
            b >>= 1;
        return res;
    def prec(self, a):
        return ("{0:.10f}".format(a))
def IO():
    try:sys.stdin = open('input.txt', 'r');sys.stdout = open('output.txt', 'w')
    except:pass
if __name__ == "__main__":
    maths = maths()
    IO()
    if test_case_run__:
        for i in range(I()):
            #print("Case #",i+1,": ",sep="",end="")
            main()

    else:
        main()