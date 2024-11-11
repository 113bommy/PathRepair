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

import math
testcases=int(input())

for j in range(testcases):
    #just try every b in the range 1,10**2 +1
    a,b,c=map(int,input().split())
    moves=4*10**4
    ans=[a,b,c]
    for s in range(1,10**4 +1):
        b1=s
        minb=10**4+1
        rem1=abs(b-s)
        if rem1<=minb:
            minb=rem1
        #find the factors of b1
        mina=10**4+1
        a1=a
        for k in range(1,math.ceil(math.sqrt(b1))+1):
            if s%k==0:
                second=s//k
                rem1=abs(a-k)
                if rem1<mina:
                    mina=rem1
                    a1=k    
                rem2=abs(a-second)
                if rem2<mina:
                    mina=rem2
                    a1=second
        minc=10**4 +1
        c1=c
        if c>=s:
            rem1=c%s
            rem2=(-c)%s
            if rem1<minc:
                minc=rem1
                c1=c-rem1
            if rem2<minc:
                minc=rem2
                c1=c+rem2
        else:
            #c<s
            rem2=(-c)%s
            if rem2<minc:
                minc=rem2
                c1=c+rem2
        if mina+minb+minc<moves:
            moves=mina+minb+minc
            ans=[a1,b1,c1]
    print(moves)
    print(*ans)