# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
import sys
from io import BytesIO, IOBase
from heapq import *
def main():
    n,m=map(int,input().split())
    a=[list(map(int,input().split())) for _ in range(m)]
    edges,j,b=[[]]*m,1,sorted(range(m),key=lambda x:a[x][0]*10000000000-a[x][1])
    c=[]
    for i in range(1,n-1):
        c.append((i+2,i))
    heapify(c)
    for i in b:
        if a[i][1]:
            edges[i]=[j,j+1]
            j+=1
        else:
            if not c:
                print(-1)
                return
            z=c[0]
            heappop(c)
            if j<z[0]:
                print(-1)
                return
            else:
                edges[i]=[z[1],z[0]]
                if z[0]+1<=n:
                    heappush(c,(z[0]+1,z[1]))
    for i in edges:
        print(*i)

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