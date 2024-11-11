#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
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
n,m=map(int,input().split())
a=list()
for i in range (m):
    s,c,d=map(int,input().split())
    a.append((c,s,d,i+1))
a.sort()
b=[0]*n
tot=0
for i in range (m):
    c=a[i][0]
    s=a[i][1]
    d=a[i][2]
    nm=a[i][3]
    free=0
    for j in range (s-1,c-1):
        if b[j]==0:
            free+=1
    #print(nm,free,d)
    if free>=d and b[c-1]==0:
        tot+=1
        b[c-1]=-1
        for j in range (s-1,c-1):
            if b[j]==0:
                b[j]=nm
                d-=1
            if d<=0:
                break
        #print(b)
    if tot>=m:
        break
if tot!=m:
    print(-1)
else:
    for i in range (n):
        if b[i]==-1:
            b[i]=m+1
    print(*b)