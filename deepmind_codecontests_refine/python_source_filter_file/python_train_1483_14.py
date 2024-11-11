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
n,m=map(int,input().split())
vals=list(map(int,input().split()))
broke=False;mcover=0
ans=[];prefcover=[]
for s in range(m):
    if s+1<=n-vals[s]+1:
        mcover=max(mcover,s+vals[s])
        ans.append(s+1);prefcover.append(mcover)
    else:
        broke=True;break
if broke==True:
    print(-1)
else:
    diff=n-mcover
    shift=[]
    for s in range(1,m):
        if diff==0:
            break
        else:
            avl=prefcover[s-1]-s
            v0=min(avl,diff)
            diff-=v0;shift.append(v0)
    if len(shift)>0:
        prefsum=[0,shift[0]]
        for s in range(1,len(shift)):
            prefsum.append(prefsum[-1]+shift[s])
        for s in range(1,m):
            if s<=len(prefsum)-1:
                ans[s]+=prefsum[s]
            else:
                ans[s]+=prefsum[-1]
    if diff==0:
        ans[-1]=n-vals[s]+1
        print(*ans)
    else:
        print(-1)