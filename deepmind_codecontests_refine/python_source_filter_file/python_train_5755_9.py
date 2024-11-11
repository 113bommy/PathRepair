#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
import threading
from collections import defaultdict


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
    x=list(map(int,input().split()))
    y=list(map(int,input().split()))
    x.sort()
    j1=n-2
    j2=1
    pre=[0]*n
    suf=[0]*n
    for i in range (n):
        while j2<n and x[j2]-x[i]<=k:
            j2+=1
        suf[i]=j2-i
    print(suf)
    for i in range (n-2,-1,-1):
        suf[i]=max(suf[i],suf[i+1])
        
    for i in range (n-1,-1,-1):
        while j1>=0 and x[i]-x[j1]<=k:
            j1-=1
        pre[i]=i-j1
    print(pre)
    for i in range (1,n):
        pre[i]=max(pre[i],pre[i-1])
    ans=1
    for i in range (n-1):
        ans=max(ans,pre[i]+suf[i+1])
    print(ans)