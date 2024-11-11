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
def fi(): return float(input())
def si(): return input()
def msi(): return map(str,input().split())
def mi(): return map(int,input().split())
def li(): return list(mi())
def lsi(): return list(msi())
 
def read():
    sys.stdin = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 

def isPrime(n) :
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
 
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def lcm(x, y):
    return (x*y)//(gcd(x,y))

mod=1000000007

def modInverse(b,m): 
    g = gcd(b, m)  
    if (g != 1):         
        return -1
    else:          
        return pow(b, m - 2, m) 

def ceil2(x,y):
    if x%y==0:
        return x//y
    else:
        return x//y+1

def modu(a,b,m): 

    a = a % m 
    inv = modInverse(b,m) 
    if(inv == -1): 
        return -999999999
    else: 
        return (inv*a)%m

from math import log,factorial,cos,tan,sin,radians,floor,sqrt,ceil,log2

import bisect
import random
import string 

from itertools import permutations

from decimal import *

getcontext().prec = 50

abc="abcdefghijklmnopqrstuvwxyz"

pi=3.141592653589793238

def main():

    for _ in range(ii()):
        n=ii()
        a=li()
        a.sort()
        for i in range(0,n-1,2):
            print(a[i+1],a[i])


        # print("Case #",end="")
        # print(_+1,end="")
        # print(": ",end="")
        # print(ans)


# region fastio

# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py

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