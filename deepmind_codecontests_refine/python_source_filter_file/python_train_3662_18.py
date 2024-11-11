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
import math
n,k=map(int,input().split())
l=list(map(int,input().split()))
s=set()
d=dict()
dis=0
for i in range(n):
    if l[i] not in s:
        dis+=1
        s.add(l[i])
        d.update({l[i]:1})
    else:
        d[l[i]]+=1
dis=math.ceil(math.log(dis,2))*n
if dis<=k:
    print(0)
else:
 u=list(s)
 u.sort()
 c=[0]*(len(u)+1)
 m=0
 c[0]=0
 #d = dict( sorted(d.items(), key=operator.itemgetter(1),reverse=True))
 c[1]=d[u[0]]
 for i in range(2,len(u)+1):
     c[i]=c[i-1]+d[u[i-1]]
 #print(c)
 k=2**(8*k//n)
 for i in range(len(c)-1,k-1,-1):
     m=max(c[i]-c[i-k],m)
     #print(c[i]-c[i-k],k)
 print(n-m)
 