# link: https://codeforces.com/contest/1562/problem/C

import os, sys
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
from math import ceil
mod = 10 ** 9 + 7 

# number of test cases
for _ in range(int(input())):
    n = int(input())
    s = input()
    f = 0
    # firstly check for continuous zeroes of length n//2
    zeroes = 0
    for i in range(n):
        if s[i] == "0": zeroes += 1
        else:           zeroes = 0
        if zeroes == (n//2):
            # answer exists
            print(i-zeroes+2, i+1, 1, n)
            f = 1
            break
    if f: continue
    # second case, that zero lies in the second half
    for i in range(n//2, n):
        if s[i] == "0":
            # answer exists
            print(1, i+1, 1, i)
            f = 1
            break
    if f: continue
    # third case
    mid = (n-1) // 2
    if s[mid] == "1":
        print(mid+1, n-1, mid+2, n)
    else:
        print(mid+1, n, mid+2, n)

