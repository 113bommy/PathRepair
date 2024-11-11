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
for j in range(int(input())):
    n=int(input())
    vals=list(map(int,input().split()))
    tot=sum(vals);count=0;ave=tot//n
    for s in range(n):
        if vals[s]<(s+1):
            count+=1
    if tot%n==0:
        if vals==[ave for s in range(n)]:
            print(0)
        else:
            if count!=n:
                ops=[]
                #move everything to 1
                for s in range(n-1,0,1):
                    if vals[s]>=(s+1):
                        ops.append((s+1,1,vals[s]//(s+1)))
                        vals[0]+=(vals[s]-(vals[s]%(s+1)));vals[s]=vals[s]%(s+1)
                        break
                for s in range(1,n):
                    ops.append((1,s+1,(-vals[s])%(s+1)))
                    new=(vals[s]+(-vals[s])%(s+1))//(s+1)
                    ops.append((s+1,1,new))
                for s in range(1,n):
                    ops.append((1,s+1,ave))
                print(len(ops))
                for i in ops:
                    print(*i)
            else:
                print(-1)
    else:
        print(-1)