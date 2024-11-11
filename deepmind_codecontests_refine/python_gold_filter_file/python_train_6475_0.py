# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
from io import BytesIO, IOBase
import sys
from string import ascii_letters

def solve(a,x,y,ch,ty):
    if ty==0:
        for j in range(y,len(a[0]),1):
            a[x][j]=ch
    else:
        for j in range(y,-1,-1):
            a[x][j]=ch
    x+=1
    for i in range(x,len(a),1):
        for j in range(0,len(a[0]),1):
            a[i][j]=ch
def main():
    al=list(ascii_letters)+[chr(i+48) for i in range(10)]
    for _ in range(int(input())):
        r,c,k=map(int,input().split())
        a=[list(input().rstrip()) for _ in range(r)]
        u,v=divmod(sum(i.count("R") for i in a),k)
        z,v,k=u+(v>0),v-1,k-1
        for i in range(r):
            if i&1:
                for j in range(c-1,-1,-1):
                    a[i][j],z=al[k],z-(a[i][j]=="R")
                    if z==0:
                        z,v,k=u+(v>0),v-1,k-1
                        if k==-1:
                            solve(a,i,j,al[0],1)
                            break
            else:
                for j in range(c):
                    a[i][j],z=al[k],z-(a[i][j]=="R")
                    if z==0:
                        z,v,k=u+(v>0),v-1,k-1
                        if k==-1:
                            solve(a,i,j,al[0],0)
                            break
            if k==-1:
                break
        for i in a:
            print("".join(i))

# FAST INPUT OUTPUT REGION

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