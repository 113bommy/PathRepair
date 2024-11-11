"""
// Author : snape_here - Susanta Mukherjee
     
 """
 
from __future__ import division, print_function
 
import os,sys
from io import BytesIO, IOBase
 
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
 
 
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())
 
 
def read():
    sys.stdin = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 
 
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

mod=1000000007

import math

import bisect

abc="abcdefghijklmnopqrstuvwxyz"

def main():

    l=[]
    s=0
    for i in range(31):
        s+=(1<<i)
        l.append(s)

    #print(*l)

    for _ in range(ii()):
        n=ii()
        c=i=0 
        while c<=n:
            c+=pow(2,i)
            i+=1 
        i-=1
        days=i 
        f=[0]*(i+1)
        for i in range(1,days+1):
            f[i]=l[i-1]
        f.append(n)
        #print(*f)
        d=[]
        for i in range(1,len(f)):
            d.append(f[i]-f[i-1])
        d.sort()
        #print(*d)
        print(days)
        for i in range(len(d)-1):
            print(d[i+1]-d[i],end=" ")
        print()


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
 
 
if __name__ == "__main__":
    #read()
    main()