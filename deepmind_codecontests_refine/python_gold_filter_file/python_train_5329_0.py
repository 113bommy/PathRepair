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
for i in range(int(input())):
    f=0
    n=int(input())
    p=list(map(int,input().split()))
    p.sort(reverse=True)
    p=[0]+p
    for j in range(1,n+1):
        p[j]+=p[j-1]
    xp,xv=map(int,input().split())
    yp,yv=map(int,input().split())
    target=int(input())*100
    xy=0
    x=0
    y=0
    su=0
    if xp<yp:
        xv,yv=yv,xv
        xp,yp=yp,xp
    for k in range(1,n+1):
        su=0
        if k%xv==0 and k%yv==0:
            xy+=1
        elif k%xv==0:
            x+=1
        elif k%yv==0:
            y+=1
        su=p[xy]*(xp+yp)+p[xy+x]*(xp)-p[xy]*xp+p[xy+x+y]*yp-p[xy+x]*yp
        if su>=target:
            print(k)
            f=1
            break
    if f==0:
        print(-1)