# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
import sys
from io import BytesIO, IOBase

def check(mid,x,k):
    z=0
    for i in x:
        z+=(i[0]//mid)
        if z>=k:
            return 1
    return 0

def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    ma=max(a)
    b=[0]*(ma+1)
    for i in a:
        b[i]+=1
    c=[]
    for i in range(1,ma+1):
        if b[i]:
            c.append([b[i],i])
    lo,hi,ans=1,n,0
    while lo<=hi:
        mid=(lo+hi)//2
        if check(mid,c,k):
            ans=mid
            lo=mid+1
        else:
            hi=mid-1
    d=[]
    for i in c:
        for j in range(i[0]//ans):
            d.append(i[1])
    print(*d[:k])

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
