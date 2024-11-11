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
print = lambda s: sys.stdout.write(str(s) + "\n")
 

def f(n,p):
    if n == 1:
        return []

    if p[-1] == n and p[-2] == n-1:
        return f(n-2, p[:-2])

    i = p.index(n)
    
    ans = []
    # action 1
    ans.append(i+1)
    p[0:i+1] = p[0:i+1][::-1]
    goTo5 = False

    j = p.index(n-1)
    if j == 1:
        goTo5 = True

    if not goTo5:
        # action 2
        ans.append(j-1)
        p[0:j] = p[0:j][::-1]
        
        # action 3
        ans.append(j+1)
        p[0:j+2] = p[0:j+2][::-1]

        # action 4
        ans.append(3)
        p[0:3] = p[0:3][::-1]

    # action 5
    ans.append(n)
    p = p[::-1]

    return ans + f(n-2, p[:-2])

def solve():
    n = int(input())
    p = list(map(int,input().split()))

    expectedOdd = list()
    actualOdd = list()
    
    for i in range(0,n,2):
        if p[i]%2 == 0:
            print(-1)
            return

    ans = list(f(n,p))
    print(len(ans))
    if ans:
        print(" ".join(str(x) for x in ans))

for nt in range(int(input())):
    solve()
