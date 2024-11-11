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

testcases=int(input())

for j in range(testcases):
    values=list(map(int,input().split()))
    n=values[0]
    m=values[1]
    if n*m%2==1:
        row1=[]
        row2=[]
        for p in range(m):
            if p%2==0:
                row1.append("B")
                row2.append("W")
            elif p%2==1:
                row1.append("W")
                row2.append("B")
        checker=0
        for s in range(n):
            if checker==0:
                print("".join(row1))
            elif checker==1:
                print("".join(row2))
            checker+=1
            checker=checker%2
    elif n*m%2==0:
        row1=[]
        row2=[]
        for p in range(m):
            if p%2==0:
                row1.append("B")
                row2.append("W")
            elif p%2==1:
                row1.append("W")
                row2.append("B")
        row0=row1+[]
        row0[1]="B"
        for s in range(n):
            if s==0:
                print("".join(row0))
            else:
                if p%2==0:
                    print("".join(row1))
                else:
                    print("".join(row2))