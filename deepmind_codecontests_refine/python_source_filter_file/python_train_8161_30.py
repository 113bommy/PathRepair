"""
 
n=int(z())
 
for _ in range(int(z())):
 
x=int(z())
 
l=list(map(int,z().split()))
 
n=int(z())
 
l=sorted(list(map(int,z().split())))[::-1]
 
a,b=map(int,z().split())
 
l=set(map(int,z().split()))
 
led=(6,2,5,5,4,5,6,3,7,6)
 
vowel={'a':0,'e':0,'i':0,'o':0,'u':0}
 
color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]
 
"""
#!/usr/bin/env python
#pyrival orz
import os
import sys
from io import BytesIO, IOBase

input = sys.stdin.readline
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

from math import inf
def main():
    try:
        n, m = invr()
        a = [[0 for _ in range(n)] for __ in range(m)]
        for i in range(n):
            for j in range(m):
                if i == j:
                    a[i][j] = m
        
        for i in range(n):
            print(*a[i], sep = " ")






    except Exception as e:
        print(e)

        

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