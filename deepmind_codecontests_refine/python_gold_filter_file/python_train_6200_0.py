# @oj: codeforces
# @id: hitwanyang
# @email: 296866643@qq.com
# @date: 2020-08-20 23:46
# @url:https://codeforc.es/problemset/problem/702/B

import sys,os
from io import BytesIO, IOBase
import collections,itertools,bisect,heapq,math,string
from decimal import *
# region fastio

BUFSIZE = 8192

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
# ------------------------------
def main():
    n=int(input())
    a=list(map(int,input().split()))
    d=collections.Counter(a)
    k=d.keys()
    ans=0
    for i in range(1,32):
        t=2**i
        temp=collections.defaultdict()
        for j in k:
            temp[j]=False
        for j in k:
            if not temp[j]:
                if 2*j==t:
                    ans+=d[j]*(d[j]-1)//2
                    temp[j]=True
                else:
                    if t-j in k:
                        ans+=d[j]*d[t-j]
                        temp[j],temp[t-j]=True,True
    print (ans)
if __name__ == "__main__":
    main()