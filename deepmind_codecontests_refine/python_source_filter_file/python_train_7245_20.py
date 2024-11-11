# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
import sys
from io import BytesIO, IOBase
from collections import deque
def check(x,y):
    if x==4 and y==0:
        print("YES")
        exit(0)
def main():
    n=10
    a=[input().rstrip() for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if j+4<n:
                c,d=0,0
                for k in range(5):
                    if a[i][j+k]=="X":
                        c+=1
                    elif a[i][j+k]=="O":
                        d+=1
                check(c,d)
            if i+4<n:
                c, d = 0, 0
                for k in range(5):
                    if a[i+k][j] == "X":
                        c+=1
                    elif a[i+k][j] == "O":
                        d+=1
                check(c,d)
            if i+4<n and j+4<n:
                c,d=0,0
                for k in range(5):
                    if a[i+k][j+k]=="X":
                        c+=1
                    elif a[i+k][j+k] == "O":
                        d+=1
                check(c,d)
            if i-4>-1 and j-4>-1:
                c,d=0,0
                for k in range(5):
                    if a[i-k][j-k]=="X":
                        c+=1
                    elif a[i-k][j-k] == "O":
                        d+=1
                check(c,d)

    print("NO")

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

if __name__ == "__main__":
    main()