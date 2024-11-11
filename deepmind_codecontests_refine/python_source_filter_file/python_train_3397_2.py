#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
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
n,m,x=map(int,input().split())
a=list()
b=list()
shift=0
for i in range (n):
    s=input()
    for j in range (m):
        if s[j]=='S':
            b.append((i,j))
            shift=1
        else:
            a.append((s[j],i,j))
d=dict()
for i in range (len(a)):
    dist=10**9
    x1=a[i][1]
    y1=a[i][2]
    if a[i][0] in d:
        dist=d[a[i][0]]
    for j in range (len(b)):
        x2=b[j][0]
        y2=b[j][1]
        d1=((x2-x1)**2+(y2-y1)**2)**0.5
        dist=min(dist,d1)
    d[a[i][0]]=dist
l=int(input())
s=input()
ch=1
c=0
for i in s:
    if ord(i)>=97 and ord(i)<=122:
        if i not in d:
            ch=0
            break
    else:
        cr=chr(ord(i)+32)
        if cr not in d or shift==0:
            ch=0
            break
        else:
            dist=d[cr]
            if dist>x:
                c+=dist
if ch==0:
    print(-1)
else:
    print(c)