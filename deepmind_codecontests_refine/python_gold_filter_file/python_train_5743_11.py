#------------------------------warmup----------------------------
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
 
#-------------------game starts now-----------------------------------------------------
n,m=map(int,input().split())
a=[]
b=[]
for i in range(n):
    l=list(map(int,input().split()))
    a.append(l)
for i in range(n):
    l=list(map(int,input().split()))
    b.append(l)
f=0
#print(a,b)
for i in range(n):
    for j in range(m):
        #t=0
        if a[i][j]>b[i][j]:
            a[i][j],b[i][j]=b[i][j],a[i][j]
for i in range(n):
    for j in range(m):   
        t=0
        if i>=1 and a[i][j]<=a[i-1][j]:
            t=1
        elif j>=1 and a[i][j]<=a[i][j-1]:
            t=1
        elif i<n-1 and a[i][j]>=a[i+1][j]:
            t=1
        elif j<m-1 and a[i][j]>=a[i][j+1]:
            t=1   
        elif i>=1 and b[i][j]<=b[i-1][j]:
            t=1
        elif j>=1 and b[i][j]<b[i][j-1]:
            t=1
        elif i<n-1 and b[i][j]>=b[i+1][j]:
            t=1
        elif j<m-1 and b[i][j]>=b[i][j+1]:
            t=1   
        if t==1:
            f=1
            break
#print(a,b)       
if f==1:
    print("Impossible")
else:
    print("Possible")        
        
    