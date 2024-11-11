#------------------------------warmup----------------------------
import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
 
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
 
#-------------------game starts now----------------------------------------------------
n,a,b=map(int,input().split())
c=list()
for i in range (n):
    x,y=map(int,input().split())
    c.append((x,y))
m=0
for i in range (n-1):
    for j in range (i+1,n):
        x1=c[i][0]
        y1=c[i][1]
        x2=c[j][0]
        y2=c[j][1]
        if (x1<=a and x2<=a and y1<=b and y2<=b and (x1+x2<=a or y1+y2<=b)) or (
                x1<=a and y2<=a and y1<=b and x2<=b and (x1+y2<=a or y1+x2<=b)) or (
                    y1<=a and x1<=a and x1<=b and y2<=b and (y1+x2<=a and x1+y2<=b)) or (
                        y1<=a and y2<=a and x1<=b and x2<=b and (y1+y2<=a and x1+x2<=b)):
                            m=max(m,x1*y1+x2*y2)
print(m)