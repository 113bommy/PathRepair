from collections import Counter
import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192
import math

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
def divs(n, start=2):
    divisors = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if n / i == i:
                divisors.append(i)
            else:
                divisors.extend([i, n // i])
    return divisors
#import sys
#inf = float("inf")
#mod = 1000000007
#def array(): return list(map(int, sys.stdin.readline().split()))
#def intt(): return map(int, sys.stdin.readline().split())
#from bisect import bisect_left
#import sys
##########################################################
#it=iter(t)
#if all(c in it for c in s):
#ls.sort(key=lambda x: (x[0], x[1]))
# ls.sort(key=lambda x: (x[0], x[1]))
#n, k = map(int, sys.stdin.readline().split())
#arr = list(map(int, sys.stdin.readline().split()))
#u,v = map(int, sys.stdin.readline().split())
#n,k=map(int, input().split())
#arr = list(map(int, sys.stdin.readline().split()))
#n = int(sys.stdin.readline())
#arr = list(map(int, sys.stdin.readline().split()))
#n=int(sys.stdin.readline())
import sys
import bisect
#for i in range(int(input())):
#n,x,y=map(int, input().split())
from collections import Counter
n=int(input())
arr=list(map(int,input().split()))

c=Counter(arr)
m=int(input())
ls=list(map(int,input().split()))
l=list(map(int,input().split()))
ansb=ansc=ans=0
for i in range(m):
    cntb,cntc,ans=c.get(ls[i],0),c.get(l[i],0),0
    if ansb<cntb or (ansb==cntb and ansc<cntc):
        ansb,ansc,ans=cntb,cntc,i
print(ans+1)