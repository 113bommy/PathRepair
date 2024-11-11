import os
import sys
from io import BytesIO, IOBase
from math import ceil

def main():
    for t in range(int(input())):
        n=int(input())
        a = input().rstrip()
        n=len(a)
        su=0
        b=a.count("L")
        if b==n or b==0:
            print(ceil(n/3))
        else:
            ll,lc,rl,rc=1,0,1,n-1
            for i in range(1,n):
                if a[i]!=a[i-1]:
                    lc=i
                    break
                ll+=1
            for i in range(n-1,0,-1):
                if a[i] != a[i - 1]:
                    rc= i
                    break
                rl+= 1
            if a[0]==a[-1]:
                su+=((ll+rl)//3)
            else:
                su=su+ll//3+rl//3
            l=0
            for i in range(lc,rc-1):
                if a[i]==a[i+1]:
                    l=l+(2 if l==0 else 1)
                if a[i]!=a[i+1] or i==rc-2:
                    if l>=3:
                        su+=(l//3)
                    l=0
            print(su)
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