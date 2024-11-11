import math
import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType
from collections import defaultdict
BUFSIZE = 8192
from bisect import bisect_left
from bisect import bisect_right


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
from collections import deque

def ceil(a,b):
    if(a<=0):
        return 0
    if(a%b==0):
        return(a//b)
    else:
        return ((a//b)+1)

t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    #n,m=map(int,input().split())
    b=list(map(int,input().split()))
    if(n==1):
        print(k+1)
    else:
        j=0
        ans=0
        k+=1
        while(j<n-1):
            d=b[j+1]-b[j]
            r=10**d-1
            if(r>=k):
                ans+=k*(10**j)
                k=0
                break

            else:
                k-=r
                ans+=r*(10**j)
            j+=1
        ans+=k*(10**b[n-1])
        print(ans)













































































