import os
from io import BytesIO, IOBase
import sys
from bisect import bisect_right,bisect_left
def main():
    for _ in range(int(input())):
        n,k=map(int,input().split())
        x=list(map(int,input().split()))
        y=list(map(int,input().split()))
        if n==1:
            print(1)
        else:
            x.sort()
            l=[]
            r=[]
            for i in range(n):
                z=bisect_right(x,x[i]+k)
                y=bisect_left(x,x[i]-k)
                r.append(z-i)
                l.append(i-y+1)
            for i in range(1,n):
                l[i]=max(l[i],l[i-1])
                r[n-i-1]=max(r[n-i-1],r[n-i])
            ma=0
            for i in range(n-1):
                ma=max(l[i]+r[i+1],ma)
            print(ma)
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