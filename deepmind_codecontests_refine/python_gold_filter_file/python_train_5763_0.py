import os
import sys
from io import BytesIO, IOBase
from collections import Counter

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


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


def main():
    # = int(input())
    # = list(map(int, input().split()))
    # = input()
    n,m=map(int, input().split())
    a=[]
    somrows=[]
    somcols=[]
    for i in range(n):
        a.append(list(map(int, input().split())))
        somrows.append(sum(a[i]))
    for j in range(m):
        curr=0
        for i in range(n):
            curr+=a[i][j]
        somcols.append(curr)
    xs=[]
    ys=[]
    xmin=ymin=float('inf')
    xind=yind=-1
    for i in range(0, 4*m+1, 4):
        curr=0
        for j in range(2, 4*m, 4):
            curr+=(j-i)*(j-i)*(somcols[j//4])
        if curr<xmin:
            xmin=curr
            xind=i//4
        xs.append(curr)
        #print('')
    for i in range(0, 4*n+1, 4):
        curr=0
        for j in range(2, 4*n, 4):
            curr+=(j-i)*(j-i)*(somrows[j//4])
        ys.append(curr)
        if curr<ymin:
            ymin=curr
            yind=i//4
    print(xmin+ymin)
    print(yind, xind)


    return


if __name__ == "__main__":
    main()