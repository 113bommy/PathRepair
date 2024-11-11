# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def change(res,el,fac):
    if el == 'U':
        res[1] += fac
    elif el == 'D':
        res[1] -= fac
    elif el == 'R':
        res[0] += fac
    else:
        res[0] -= fac

def check(mid,s,res,x,y,n):
    for i in range(mid):
        change(res,s[i],-1)
    if abs(res[0]-x)+abs(res[1]-y) <= mid:
        return 1
    for i in range(mid,n):
        change(res,s[i],-1)
        change(res,s[i-mid],1)
        if abs(res[0]-x)+abs(res[1]-y) <= mid:
            return 1
    return 0

def main():
    n = int(input())
    s = list(input().strip())
    x,y = map(int,input().split())
    if (x+y)&1 != n&1:
        return -1
    res = [0,0]
    for i in range(n):
        change(res,s[i],1)
    if res[0] == [x,y]:
        return 0
    hi,lo,ans = n,1,-1
    while hi >= lo:
        mid = (hi+lo)//2
        if check(mid,s,res[:],x,y,n):
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans

# Fast IO Region
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
    print(main())