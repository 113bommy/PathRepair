#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
from collections import defaultdict
from itertools import permutations
 

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
 
#-------------------game starts now-----------------------------------------------------
mod=10**9+7
def func(x):
    power=0
    copy=x
    even=0
    odd=0
    while x>0:
        if power%2==0:
            odd+=min(2**power,x)
        else:
            even+=min(2**power,x)
        x-=min(x,2**power)
        power+=1
    c1=(even%mod)*((even+1)%mod)
    c1%=mod
    c2=(odd%mod)*(odd%mod)
    c2%=mod
    r=c1+c2
    return (r,even,odd)

l,r=map(int,input().split())
res=func(r)[0]-func(l-1)[0]
print(res)
#print(func(r))
#print(func(l-1))