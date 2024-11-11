#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
#from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
#from bisect import bisect_right as br               #c++ upperbound br(array,element)
 
 
def main():
    x,y=map(int,input().split(" "))
    n=int(input())-1
    n=n%6
    mod=int(1e9+7)
    if n==0:
        if x>=0:
            print((x)%mod)
        else:
            print((x+mod)%mod)
    if n==1:
        if y>=0:
            print((y)%mod)
        else:
            print((y+mod)%mod)
    if n==2:
        if y-x<=0:
            print((y-x+mod)%mod)
        else:
            print((y-x)%mod)
    if n==3:
        if x<=0:
            print((-x)%mod)
        else:
            print((-x+mod)%mod)
    if n==4:
        if y<=0:
            print((-y)%mod)
        else:
            print((-y+mod)%mod)
    if n==5:
        if x-y<=0:
            print((y-x+mod)%mod)
        else:
            print((y-x)%mod)

        

#-----------------------------BOSS-------------------------------------!
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

# endregion

if __name__ == "__main__":
    main()