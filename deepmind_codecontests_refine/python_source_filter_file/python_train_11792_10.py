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
for _ in range (int(input())):
    n,k=map(int,input().split())
    l1,r1=map(int,input().split())
    l2,r2=map(int,input().split())
    over=max(0,min(r1,r2)-max(l1,l2))
    cover=max(0,max(l1,l2)-min(r1,r2))
    extend=max(r1,r2)-min(l1,l2)-over
    #print(over,cover,extend)
    i=over*n
    copy=n
    operation=0
    if i<k:
        m=min(k-i,extend)
        operation+=cover+m
        i+=m
        n-=1
    while i<k:
        m=min(k-i,extend)
        if n==0:
            m=i-k
            operation+=2*m
            i=k
        elif cover<m:
            operation+=m+cover
            i+=m
            n-=1
        else:
            operation+=2*m
            i+=m
    print(operation)