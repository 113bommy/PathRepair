#    AUTHOR :-   Sagnik Mitra
#    Jalpaiguri Govt. Engg College

from __future__ import division, print_function
 
import os,sys
from io import BytesIO, IOBase
 
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
 
def ii(): return int(input())
def fi(): return float(input())
def si(): return input()
def msi(): return map(str,input().split())
def mi(): return map(int,input().split())
def li(): return list(mi())
def lsi(): return list(msi())
 

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def lcm(x, y):
    return (x*y)//(gcd(x,y))

mod=1000000007

def ceil(x,y):
    if x%y==0:
        return x//y
    else:
        return x//y+1

from math import log,factorial,cos,tan,sin,radians,floor,sqrt,log2

import bisect
import random
import string 

from decimal import *


def main():
    
    a=li()
    s=sum(a)
    if s&1:
        print("NO")
        return
    s=s//2
    for i in range(0,6):
        for j in range(1,6):
            for k in range(2,6):
                if a[i]+a[j]+a[k]==s:
                    print("YES")
                    return
    print("NO")


# region fastio-----------------------------------------------------------------
 
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
 
# endregion------------------------------------------------------------------

 
if __name__ == "__main__":
    #read()
    main()