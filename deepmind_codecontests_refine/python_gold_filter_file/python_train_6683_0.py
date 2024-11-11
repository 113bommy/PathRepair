# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase
 
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
 
# ------------------- fast io --------------------

import bisect
n,k=map(int,input().split())
vals=list(map(int,input().split()))
vals.sort()
a1=[]        
a2=[]
if n%2==1:
    moves=0
    for s in range(n//2):
        moves+=abs(vals[s+1]-vals[s])*(s+1)
        moves+=abs(vals[-1-(s+1)]-vals[-1-s])*(s+1)
        a1.append(moves)
        a2.append(abs(vals[s+1]-vals[-1-(s+1)]))
else:
    moves=0
    for s in range(n//2 -1):
        moves+=abs(vals[s+1]-vals[s])*(s+1)
        moves+=abs(vals[-1-(s+1)]-vals[-1-s])*(s+1)
        a1.append(moves)
        a2.append(abs(vals[s+1]-vals[-1-(s+1)]))
    moves+=abs(vals[n//2 -1]-vals[n//2])*(n//2)
    a1.append(moves)
    a2.append(0)
ind=bisect.bisect_left(a1,k)
if k<a1[0]:
    print(abs(vals[0]-vals[-1])-k)
elif k>=a1[-1]:
    print(0)
else:
    if k==a1[ind]:
        print(a2[ind])
    elif k<a1[ind]:
        print(a2[ind-1]-(k-a1[ind-1])//(ind+1))