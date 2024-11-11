#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
#from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
#from bisect import bisect_right as br               #c++ upperbound br(array,element)
 
 
def main():
    n=int(input())
    a=list(map(int,input().split(" ")))
    ans=1
    if n==1:
        print(1)
        return
    dp=[1 for x in range(n+1)]
    dpb=[1 for x in range(n+1)]
    cnt=1
    for x in range(1,n):
        if a[x]>a[x-1]:
            cnt+=1
            dp[x]=cnt
        else:
            cnt=1
    cnt=1
    for x in range(n-2,-1,-1):
        if a[x+1]>a[x]:
            cnt+=1
            dpb[x]=cnt
        else:
            cnt=1
    ans=1
    for x in range(n):
        if x+1<n and x-1>=0 and a[x+1]-a[x-1]>=2:
            ans=max(ans,dp[x-1]+dpb[x+1]+1)
        ans=max(ans,dp[x]+1,dpb[x]+1)
    print(ans)





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