#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
#from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
#from bisect import bisect_right as br               #c++ upperbound br(array,element)
import math
mod=int(1e9+7)
def getfactor(num):
    boss=set()
    for x in range(1,math.floor(math.sqrt(num))+2):
        if num%x==0:
            boss.add(x)
            boss.add(num//x)
    return list(boss)
def main():
    n=int(input())
    
    a=list(map(int,input().split(" ")))
    if n==1:
        print(1)
        return
    dp=[0 for x in range(1111111)]
    #prev=[[0 for x in range(111111)]]
    dp[0]=1
    for x in range(0,n):
        boss=getfactor(a[x])
        boss.sort(reverse=True)
        for x in range(len(boss)):
            dp[boss[x]]+=dp[boss[x]-1]
            dp[boss[x]]%=mod
    ans=0
    for x in range(1,n):
        ans=(ans%mod+dp[x]%mod)%mod
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