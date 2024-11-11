import os
import sys
from io import BytesIO, IOBase
# region fastio
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
def bsearch(mn, mx, func):
    #func(i)=False を満たす最大のi (mn<=i<mx)
    idx = (mx + mn)//2
    while mx-mn>1:
        if func(idx):
            idx, mx = (idx + mn)//2, idx
            continue
        idx, mn = (idx + mx)//2, idx
    return idx

N, = map(int, input().split())
X = list(map(int, input().split()))
sX = sum(X)
d = X[0]
if sX >= N*(N-1)//2:
    tmp = sX-N*(N-1)//2
    d = max(tmp//N, d)
m = sX - d*N
for i in range(N):
    X[i] = d
i=bsearch(0,N,lambda i : i*(i+1)//2>=m)
i+=1
for j in range(i-1):
    X[N-1-j]+=i-j-1
k=m-i*(i-1)//2
for j in range(k):
    X[N-i+j]+=1
#print(" ".join(map(str, X)))
