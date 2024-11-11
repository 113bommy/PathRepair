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

n = int(input())
a = [None]*n
for i in range(n):
    a[i] = list(map(int,input().split()))

m = int(input())
b = [None]*m
for i in range(m):
    b[i] = tuple(map(int,input().split()))

s = set(b)
if tuple(a[i][0] for i in range(n)) not in s:
    print(*tuple(a[i][0] for i in range(n)))
    exit()

mx = 0
ans = None
for choice in b:
    choice = list(choice)
    for i in range(n):
        if choice[i] > 1:
            choice[i] -= 1

            if tuple(choice) not in s:
                
                case = sum(a[i0][choice[i0]] for i0 in range(n))
                if case > mx:
                    mx = case
                    ans = choice[:]

            choice[i] += 1

print(*ans)

